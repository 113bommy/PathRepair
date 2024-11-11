n=int(input())
l=list(map(int,input().split()))
mp=0
f=0
d={25:0,50:0,100:0}
c25=0
c50=0
for i in l:
	if i==25:
		c25+=1
	elif i==50:
		if c25==0:
			f=1
			break
		else:
			c25-=1
			c50+=1
	else:
		if c50>0 and c25>0:
			c50-=1
			c25-=1
		elif c25>=3:
			c25-=3
		else:
			f=1
			break
if f==0:
	print('YES')
else:
	print('NO')