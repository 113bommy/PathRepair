from _collections import deque
n,m=map(int,input().split())
M=[[] for _ in range(n)]
ANS=[-1]*n
ANS[0]=0
for i in range(m):
    a,b=map(int,input().split())
    M[b-1].append(a-1)
    M[a-1].append(b-1)

q=deque([0])

while q:
    s=q.popleft()
    for x in M[s]:
        if ANS[x]!=-1:
            continue
        q.append(x)
        ANS[x]=s
print('Yes')
for ans in ANS[1:]:
    print(ans+1)