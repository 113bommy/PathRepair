# from debug import debug
import sys
from math import ceil, gcd
input = sys.stdin.readline

n = int(input())
lis = list(map(int , input().split()))
m = max(lis)
diff = [m-lis[i] for i in range(n)]
g = 0
for i in range(n):
	g = gcd(g, diff[i])
ans = 0
for i in range(n):
	ans += diff[i]//g
print(ans, g)
