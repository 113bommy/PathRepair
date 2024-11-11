def ret(n,k,t):
	if t<k:
		return t
	elif t>=k and t<=n:
		return k
	else:
		return n+k-t
n,k,t=map(int,input().split())
print(ret(n,k,t))