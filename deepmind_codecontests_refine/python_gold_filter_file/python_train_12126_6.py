vis = [0]*26
ans = []
graph = [[] for _ in range(26)]
A = ord('a')

def topo1(i):
    s = [(i,1)]
    while s:
        i,state = s.pop()
        if state:
            s.append((i,0))
            vis[i]=1
            for j in graph[i]:
                if vis[j]==1:
                    return False
                elif vis[j]==0:
                    s.append((j,1))
        else:
            vis[i]=2
            ans.append(chr(i+A))
    return True

def topo(i):
    vis[i]=1
    for j in graph[i]:
        if vis[j]==1:
            return False
        elif vis[j]==0:
            if not topo(j):
                return False
    vis[i]=2
    ans.append(chr(i+A))
    return True

def solve():
    t = int(input())
    names = []
    for _ in range(t):
        names.append(input())
    exist = True
    for k in range(t-1):
        i = 0
        while True:
            if len(names[k])==i:
                break

            elif len(names[k+1])==i:
                exist = False
                break

            elif names[k][i]!=names[k+1][i]:
                a,b = ord(names[k][i])-A, ord(names[k+1][i])-A
                graph[a].append(b)
                break
            else:
                i+=1

    if exist:
        for i in range(26):
            if vis[i]==0:
                exist = topo(i)
            if not exist:
                break
        if exist:
            print(''.join(reversed(ans)))
            
    if not exist:
        print('Impossible')
    
solve()