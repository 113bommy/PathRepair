import math
k = int(input())
ans = 0
for a in range(1, k+1):
  for b in range(1, k+1):
    for c in range(1, k+1):
      ans += math.gcd(a, math.gcd(b, c))
print(ans)