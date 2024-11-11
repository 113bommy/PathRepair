from collections import deque

N=int(input())
IN=[[] for i in range(N)]
OUT=[-1 for i in range(N)]
p=list(map(int,input().split()))
for i in range(N):
    IN[p[i]-1].append(i)
    OUT[i]=p[i]-1

deg=[len(IN[i]) for i in range(N)]

deq=deque([v for v in range(N) if deg[v]==0])
res=[]
while deq:
    v=deq.popleft()
    res.append(v)
    deg[OUT[v]]-=1
    if deg[OUT[v]]==0:
        deq.append(OUT[v])

if len(res)==N:
    print("POSSIBLE")
    exit()

start=-1
for i in range(N):
    if deg[i]>0:
        start=i
        break

cycle=[start]
while True:
    nv=OUT[cycle[-1]]
    if nv!=start:
        cycle.append(nv)
    else:
        break


dp=[-1]*N
for v in res:
    mex=[False]*(len(IN[v])+1)
    for pv in IN[v]:
        if dp[pv]<=len(IN[v]):
            mex[dp[pv]]=True
    for i in range(len(mex)):
        if not mex[i]:
            dp[v]=i
            break

m0=-1
m1=-1
mex=[False]*(len(IN[start])+2)
for pv in IN[start]:
    if dp[pv]!=-1 and dp[pv]<=len(IN[v])+1:
        mex[dp[pv]]=True
for i in range(len(mex)):
    if not mex[i]:
        if m0==-1:
            m0=i
        else:
            m1=i
            break

#m0
dp[start]=m0
for i in range(1,len(cycle)):
    v=cycle[i]
    temp=-1
    mex=[False]*(len(IN[v])+1)
    for pv in IN[v]:
        if dp[pv]<=len(IN[v]):
            mex[dp[pv]]=True
    for i in range(len(mex)):
        if not mex[i]:
            dp[v]=i
            break
mex=[False]*(len(IN[start])+2)
for pv in IN[start]:
    if dp[pv]!=-1 and dp[pv]<=len(IN[v])+1:
        mex[dp[pv]]=True
check=-1
for i in range(len(mex)):
    if not mex[i]:
        check=i
        break
if check==m0:
    print("POSSIBLE")
    exit()

for v in cycle:
    dp[v]=-1

#m1
dp[start]=m1
for i in range(1,len(cycle)):
    v=cycle[i]
    temp=-1
    mex=[False]*(len(IN[v])+1)
    for pv in IN[v]:
        if dp[pv]<=len(IN[v]):
            mex[dp[pv]]=True
    for i in range(len(mex)):
        if not mex[i]:
            dp[v]=i
            break
mex=[False]*(len(IN[start])+2)
for pv in IN[start]:
    if dp[pv]!=-1 and dp[pv]<=len(IN[start])+1:
        mex[dp[pv]]=True
check=-1
for i in range(len(mex)):
    if not mex[i]:
        check=i
        break
if check==m1:
    print("POSSIBLE")
    exit()

print("IMPOSSIBLE")
