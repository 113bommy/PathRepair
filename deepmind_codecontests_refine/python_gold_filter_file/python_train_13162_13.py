n, vol=map(int, input().split())
a=sorted(list(map(int, input().split())))
s=0; flag=True

for i in range(n-1):
	s+=a[i]
	if s>vol:
		flag=False;break

if flag:
	print("YES")
else:
	print("NO")