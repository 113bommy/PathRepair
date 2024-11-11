I = input
pr = print
for _ in range(int(I())):
	mn=1e9;mx=0
	y=int(I())
	for x in range(y):
		m,n=map(int,I().split())
		mx = max(mx,m)
		mn = min(mn,n)
	pr(mx-mn if y>1 and mx>mn else 0)