from collections import deque
n,m=map(int,input().split())
X=[]
M=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    X.append([a,b])
    M[a-1].append(b-1)
    M[b-1].append(a-1)
ans=0
for i in range(m):
    se={X[i][0]-1,X[i][1]-1}
    q=deque([0])
    visited=[0]*n
    while q:
        s=q.popleft()
        if visited[s]==1:
            continue
        visited[s]=1
        for x in M[s]:
            if {s,x}!=se:
                q.append(x)
    if sum(visited)!=n:
        ans+=1
print(ans)