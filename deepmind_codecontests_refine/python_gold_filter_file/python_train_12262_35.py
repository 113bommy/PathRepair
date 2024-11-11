import math
K = int(input())
ans = 0
for a in range(K):
  for b in range(K):
    for c in range(K):
      ans += math.gcd(a+1, math.gcd(b+1, c+1))
print(ans)