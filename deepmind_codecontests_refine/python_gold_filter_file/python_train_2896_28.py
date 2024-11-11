import bisect
N,K=map(int,input().split())
A=list(map(int,input().split()))

data=[]
for i in range(N):
    now=0
    for j in range(i,N):
        now+=A[j]
        data.append(now)
data.sort()
ans=0
for i in range(40,-1,-1):
    s=pow(2,i)
    idx=bisect.bisect_left(data,s)
    if len(data)-idx>=K:
        ans+=s
        data=[d-s for d in data[idx:]]
    else:
        data=[d for d in data[:idx]]+[d-s for d in data[idx:]]
        data.sort()
print(ans)