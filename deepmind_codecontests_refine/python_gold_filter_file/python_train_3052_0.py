import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
tc = 1
mod = 10**9+7
tc = int(input())
for test in range(1,tc+1):
	n = int(input())
	a = list(map(int,input().split()))
	ans = a[0]
	for i in a:
		ans = i&ans
	c = a.count(ans)
	if c>1:
		ans = (c*(c-1))%mod
		for i in range(1,n-1):
			ans = (ans*i)%mod
		# print(ans)
	else:
		ans = 0
	print(ans)