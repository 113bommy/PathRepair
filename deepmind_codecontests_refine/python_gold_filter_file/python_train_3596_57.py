a,b = map(int,input().split())
c =0
for i in range(a):
	a = list(input().split())
	if a[0] == "+":
		b+=int(a[1])
	else:
		if b-int(a[1])>=0:
			b-=int(a[1])
		else:
			c+=1
print(b,c)
