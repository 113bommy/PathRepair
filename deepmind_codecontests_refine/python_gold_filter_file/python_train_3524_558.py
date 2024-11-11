import math
n = int(input())
ans = math.factorial(n) % (10**9+7)
print(ans)