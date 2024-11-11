N = int(input())
uvw = [[int(x) for x in input().split()] for _ in range(N-1)]

path = [[] for _ in range(N)]

ans = [-1]*N
ans[0] = 0

for u,v,w in uvw:
    path[u-1].append([v-1,w%2])
    path[v-1].append([u-1,w%2])
    
Q = [0]     
while Q:
    v = Q.pop(-1)
    for p,d in path[v]:
        if ans[p] == -1:
            ans[p] = (ans[v]+d)%2
            Q.append(p)
            
for a in ans:
    print(a)
