import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n, r1, r2, r3, d = mints()
	s = min(r1,r3)
	r2s = r2 + s
	a = list(mints())
	dp = [1<<63]*n#[[int(9e18)]*n for i in range(3)]
	dp[n-1] = min(s*a[n-1] + r3, d*2 + min(r2s, s*(a[n-1]+2)))
	#print(s*a[n-2] + r3 + d + dp[n-1], min(r2s, s*(a[n-1]+2)) + min(r2s, s*(a[n-2]+2)) + d*3, min(r2s, s*(a[n-2]+2)) + d + s*a[n-1] + r3 + d)
	dp[n-2] = min(s*a[n-2] + r3 + d + dp[n-1], min(r2s, s*(a[n-1]+2)) + min(r2s, s*(a[n-2]+2)) + d*3)
	dp[n-2] = min(dp[n-2], min(r2s, s*(a[n-2] + 2)) + d + s*a[n-1] + r3 + d)
	for i in range(n-3,-1,-1):
		dd = s*a[i] + r3 + d + dp[i+1]
		x = min(s*a[i] + r3, min(r2s, s*(a[i]+2))) + min(s*a[i+1] + r3, min(r2s, s*(a[i+1]+2)))
		#print(dd, x + dp[i+2] + d*4)
		dp[i] = min(dd, x + dp[i+2] + d*4)
	#print(dp)
	print(dp[0])

solve()
