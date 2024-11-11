n=int(input())
c=[list(map(int,input().split())) for i in range(3)]
edges=[[] for i in range(n)]
for i in range(n-1):
    u,v=map(int,input().split())
    edges[u-1].append(v-1)
    edges[v-1].append(u-1)
for i in range(n):
    if len(edges[i])>2:
        print(-1)
        exit()
path=[]
for i in range(n):
    if len(edges[i])==1:
        path.append(i)
        break
#print(path)
#print(edges)
seen=[False]*n
seen[path[-1]]=True
#exit()
while True:
    for i in edges[path[-1]]:
        if not seen[i]:
            path.append(i)
            seen[i]=True
            break
    else:
        break
#print(path)
d=[[0]*n for i in range(3)]
for i in range(3):
    now=0
    for j in path:
        d[i][now]=c[i][j]
        now+=1
#print(d)
from itertools import permutations
ans=10**30
now=[]
for i in permutations(range(3),3):
    ans_sub=0
    now_sub=[0]*n
    for j in range(n):
        now_sub[path[j]]=i[j%3]+1
        ans_sub+=d[i[j%3]][j]
    if ans_sub<ans:
        ans=ans_sub
        now=now_sub
print(ans)
print(" ".join(map(str,now)))