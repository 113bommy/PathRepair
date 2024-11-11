import math
n = int(input())
res = 0
for i in range(1,n+1):
  for j in range(1,n+1):
    for k in range(1,n+1):
      res += math.gcd(math.gcd(i,j),k)
print(res)
