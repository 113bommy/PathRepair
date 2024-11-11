import sys
sys.setrecursionlimit(1000000)

def DFS(i):
    if done[i]:
        ans[-1]+=1
        done[i]=False
        for g in G[i]:
            if done[g]:
                DFS(g)
    else:
        return p

N,M=map(int,input().split())
G=[[] for _ in range(N)]
done=[True for _ in range(N)]

for i in range(M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    G[a].append(b)
    G[b].append(a)
ans=[]
for j in range(N):
    ans.append(0)
    if done[j]:
        DFS(j)
print(max(ans))
