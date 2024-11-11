n=int(input())
import math
ans=0
for i in range(1,n+1):
  for j in range(1,n+1):
    for k in range(1,n+1):
      ans+=math.gcd(math.gcd(i,k),j)
print(ans)