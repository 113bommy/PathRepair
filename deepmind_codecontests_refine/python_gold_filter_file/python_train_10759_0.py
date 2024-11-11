import math
N = 15
mat = 0
inf = 1000000000
answer = inf



def Get_Cycle_Length(v,graph):
    global mat
    global answer
    if len(v) == 0:      #por lo de conf 3
        answer = min(answer,mat)
        return
    end = v.pop()
    i = 0
    while i<len(v):
        se = v.pop(i)
       
        mat += graph[se][end]
        Get_Cycle_Length(v,graph)
        mat -= graph[se][end]
        v.insert(i,se)
        i+=1
    v.append(end)
    

def main():
    n,m = map(int,input().split())

    graph = [[inf] * n for i in range(n)]
    deg = [0] * n
    sum = 0

    for i in range(n):
        graph[i][i] = 0

    for i in range(m):
        x,y,w = map(int,input().split())
        x -= 1
        y -= 1
        deg[x]+=1
        deg[y]+=1
        graph[x][y] = min(graph[x][y],w)
        graph[y][x] = min(graph[y][x],w)
        sum += w

    for i in range(n):
        for j in range(n):                                                                  # aqui veo si hay algun camino de menos peso
            for k in range(n):
                graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k])

    for i in range(n):
        if graph[0][i] == inf and deg[i] > 0:
            print('-1')
            return
    v = []
    
    for i in range(n):
        if deg[i] % 2 != 0:
            v.append(i)
           
     
    Get_Cycle_Length(v,graph)
    print(sum + answer)



main()
