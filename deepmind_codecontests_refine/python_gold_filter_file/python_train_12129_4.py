def s():
	n = int(input())
	a = [0]
	a.extend(map(int,input().split()))
	b = list(map(int,input().split()))
	b.append(0)
	c = list(map(int,input().split()))
	for i in range(n-2,-1,-1):
		b[i] += b[i+1]
	for i in range(2,n):
		a[i] += a[i-1]
	r = 3*[a[-1]+b[0]+101]
	for i in range(n):
		r[-1] = a[i]+b[i]+c[i]
		r.sort()
	print(sum(r[0:2]))
s()