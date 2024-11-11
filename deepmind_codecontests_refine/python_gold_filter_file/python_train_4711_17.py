no =int(input())
res = []

for i in range(no):
	a=int(input())
	x=list(map(int,input().split()))
	x=sorted(x)
	val =99999
	for i in range(1,a):
		val=min(val,x[i]-x[i-1])
	res.append(val)
	
for i in res:
	print(i)	