#codeforces _1084A
gi = lambda : list(map(int,input().split()))
n, = gi()
l = gi()
pos = 1
ans = 1000000000000
v = 0
for j in range(1,n+1):
	ll = [(abs(pos-k)+abs(k-1)+abs(pos-1)+abs(pos-1)+abs(k-1)+abs(pos-k))*l[k-1] for k in range(1,n+1)]
	v = sum(ll)
	ans = min(ans,v)
	pos += 1
print(ans)
