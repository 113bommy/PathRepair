#codeforces797A
gi = lambda : list(map(int,input().strip().split()))
n,m = gi()
ans = []
k = 2
nn = n
while n > 0 and k <= nn:
	while n > 0 and n%k == 0:
		n //= k
		if len(ans) == m:
			ans[-1] *= k
		else:
			ans.append(k)
	k += 1
if len(ans) < m:
	print(-1)
	exit()
print(" ".join(map(str,ans)))