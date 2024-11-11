a=int(input())
b=int(input())
c=int(input())
s=0
for i in range(0,1000):
	if a<=b/2 and a<=c/4:
		s=1
		break
	else:
		a-=1
if s==1:
	print(a*1+a*2+a*4)
else:
	print(0)