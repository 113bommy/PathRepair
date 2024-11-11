a,b = map(int,input().split())
x = list(input())
z = set(x)
v =[]
if len(z) == b:
	for i in z:
		v.append(x.count(i))
	print(min(v)*b)
else:
	print(0)

