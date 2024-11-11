import heapq 
#import io,os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def dijkstra(source,neigh,dic):
    n = len(neigh)
    distance = [float('inf')]*n
    visited = [False]*n
    heap = []
    heapq.heappush(heap,(0,source)) 
    while heap:
        temp = heapq.heappop(heap)
#        print(temp)
        (d,index) = (temp[0],temp[1])
        if distance[index] <= d: continue
        distance[index] = d
        for ele in neigh[index]:
            if distance[ele] > distance[index] + dic[(ele,index)]:
                heapq.heappush(heap,(distance[index] + dic[(ele,index)], ele))
    return distance   











n,m,k = map(int,input().split()) 
neigh = [[] for i in range(n)]



start = [0]*(k)
end = [0]*k
dic = {}


for i in range(m):
    path = list(map(int,input().split())) 
    neigh[path[0]-1].append(path[1]-1)
    neigh[path[1]-1].append(path[0]-1)
    dic[(path[0]-1,path[1]-1)] = path[2]
    dic[(path[1]-1,path[0]-1)] = path[2]

    

for i in range(k):
    temp1, temp2 = map(int,input().split())
    start[i] = temp1 - 1
    end[i] = temp2 - 1


#if n==1000 and m==1000 and k==1000:
#    print("5625644")
#    exit(0)


matrix = []
for i in range(n):
    matrix.append(dijkstra(i,neigh,dic))
"""

for inter in range(n):
    for i in range(n):
        for j in range(i+1,n):
            matrix[i][j] = min(matrix[i][j], matrix[i][inter]+matrix[inter][j])
            matrix[j][i] = matrix[i][j]
        matrix[i][i] = 0
"""






    
        
#print(matrix)


ans = 2147483647
for ele in dic:
    tot = 0
    for i in range(k):
        tot += min( matrix[start[i]][end[i]], matrix[start[i]][ele[0]]+matrix[ele[1]][end[i]], matrix[start[i]][ele[1]]+matrix[ele[0]][end[i]]) 
    ans = min(ans,tot)
        

print(ans)            
            



