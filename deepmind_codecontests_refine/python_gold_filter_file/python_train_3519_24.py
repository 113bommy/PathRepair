import bisect
N,K=map(int,input().split())
V=list(map(int,input().split()))

sV=sorted(V)
ans=0
for i in range(N):
  for j in range(N-i+1):
    if i+j<=K:
      if i+j>=N:
        L=sV
      else:
        L=V[:i]+V[N-j:]
        L.sort()
      k=bisect.bisect_left(L,0)
      kans=sum(L[min(max(0,K-i-j),k):])
      ans=max(ans,kans)
print(ans)