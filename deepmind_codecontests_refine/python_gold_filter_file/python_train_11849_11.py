N=int(input())
s=list(input())
from collections import Counter
d=Counter(s)
ans=1
for v in d.values():
  ans*=(v+1)
ans-=1
ans=ans%(10**9+7)
print(ans)
