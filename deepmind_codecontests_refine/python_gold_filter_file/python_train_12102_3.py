from collections import defaultdict as dd
for _ in range(int(input())):
	a,b = map(int,input().split())
	c = list(map(int,input().split()))
	d = dd(lambda : 0)
	for i in c:
		d[i]+=1
	v = list(d.keys())
	if len(v)>b:
		print(-1)
	else:
		print(a*b)
		for i in range(1,b-len(v)+1):
			v.append(i)
		print(*v*a)