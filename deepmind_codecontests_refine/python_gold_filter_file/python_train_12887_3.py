import bisect

n=int(input())
L=sorted(list(map(int,input().split())))

ans=0
for i in range(n-1):
  for j in range(i+1,n):
    idx=bisect.bisect_left(L,L[j]+L[i])
    ans+=max(0,idx-j-1)

print(ans)