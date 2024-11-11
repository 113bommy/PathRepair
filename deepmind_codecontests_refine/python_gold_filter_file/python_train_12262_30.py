import math
n = int(input())
ans = 0
for i in range(1,n+1):
  for j in range(1, n+1):
    for k in range(1, n+1):
      ans += math.gcd(i, math.gcd(j, k))
print(ans)