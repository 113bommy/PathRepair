import math
n=int(input())
x=list(map(int, input().split()))
c=[]
for i in range(4,0,-1):
	c.append(x.count(i))
res=0
res+=c.pop(0)
res+=c[1]//2
c[1]=c[1]%2
m=min(c[0],c[2])
res+=m
c[0]-=m
c[2]-=m
res+=c[0]
if c[1]==1 and c[2]==1:
	res+=1
	c[2]-=1
elif c[1]==1 and c[2]>=2:
	res+=1
	c[2]-=2
elif c[1]==1:
	res+=1
res+=math.ceil(c[2]/4)
print(res)
