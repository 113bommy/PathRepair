a=int(input())
b=[]
if a==0:
	print(0)
while a:
	b.append(a&1)
	a-=a&1
	a=int(a/-2)
print(''.join(map(str,b[::-1])))