import bisect
N=int(input())
L=list(map(int,input().split()))
L.sort()
ans=0
for n in range(1,N):
  b=L[n]
  for k in range(n):
    a=L[k]
    index=bisect.bisect_left(L,a+b)
    ans+=(index-n-1)
print(ans)