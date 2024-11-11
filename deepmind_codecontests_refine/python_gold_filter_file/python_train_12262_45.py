import math
K = int(input())
S = 0
for i in range(1,K+1):
  for j in range(1,K+1):
    for l in range(1,K+1):
      S = S + math.gcd(l, math.gcd(j,i))

print(S)
