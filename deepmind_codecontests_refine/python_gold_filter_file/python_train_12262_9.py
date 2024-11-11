from math import gcd
k=int(input())
ans=0
for p in range(1,k+1):
  for q in range(1,k+1):
    for r in range(1,k+1):
      ans+=gcd(p,gcd(q,r))
print(ans)