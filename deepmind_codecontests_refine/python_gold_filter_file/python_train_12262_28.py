import math

k = int(input())
ans = 0
for l in range(1,k+1):
  for m in range(1,k+1):
    for n in range(1,k+1):
      ans += math.gcd(math.gcd(l,m),n)

print(ans)