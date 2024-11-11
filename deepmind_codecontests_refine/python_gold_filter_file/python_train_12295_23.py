
import sys
inputs = sys.stdin.readline

k, n = map(int, inputs().split())
if n % k == 0:
    print(n//k)
else:
    print((n//k)+1)

# Codeforcesian
# ♥
