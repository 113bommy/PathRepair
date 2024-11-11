import math 
k=int(input())
ans=0
for i in range(1,k+1):
  for j in range(1,k+1):
    for k in range(1,k+1):
      ans+=(math.gcd(math.gcd(i,j),k))
print(ans)
