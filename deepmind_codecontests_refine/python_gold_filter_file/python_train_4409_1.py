# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("output1.out",'w')
n,m=map(int,input().split())
a=[input() for i in range(n)]
for x in range(n):
	if a[x].count("*")==2:
		p=a[x]
	elif a[x].count("*")==1:
		q=a[x]
		b=x
if p.index("*")==q.index('*'):			
	z=p[::-1].index("*")
	c=m-1-z
else:
	c=p.index("*")
print(b+1,c+1)		
			

