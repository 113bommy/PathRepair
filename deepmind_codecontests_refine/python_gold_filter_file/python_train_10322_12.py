n=int(input())
a=input().split()
c,b=0,0
for i in range(n):
	if a[i]=='0':
		c=i+1
	elif a[i]=='1':
		b=i+1
if b>c:
	print(c)
else:
	print(b)