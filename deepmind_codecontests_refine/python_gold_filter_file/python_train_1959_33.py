import math
n = int(input())
a = list(map(int,input().split()))
ans = a[0]
for v in a[1:]:
  ans = math.gcd(ans,v)
print(ans)