n,m = map(int,input().split())
r = n % 2
resp = (n//2) + r

while resp <= n:
	if resp % m == 0:
		print(resp)
		break
	else:
		resp = resp + 1
if resp > n:
	print(-1)