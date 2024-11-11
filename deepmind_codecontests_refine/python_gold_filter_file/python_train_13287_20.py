
# Problem: B. Two Cakes
# Contest: Codeforces - Educational Codeforces Round 35 (Rated for Div. 2)
# URL: https://codeforces.com/contest/911/problem/B
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# Powered by CP Editor (https://github.com/cpeditor/cpeditor)

from sys import stdin
from math import floor
def get_ints(): return list(map(int, stdin.readline().strip().split()))

n,a,b = get_ints()
ans =1
for x in range(1,n):
	ans =max(ans,min(floor(a/x),floor(b/(n-x))))
print(ans)