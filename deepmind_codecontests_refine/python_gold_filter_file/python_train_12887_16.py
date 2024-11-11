n=int(input())
l=list(map(int,input().split()))
l.sort()

import bisect

ans=0
for i in range(n-2):
  for j in range(i+1,n-1):
    ind=bisect.bisect_left(l,l[i]+l[j])
    ans+=ind-j-1
print(ans)