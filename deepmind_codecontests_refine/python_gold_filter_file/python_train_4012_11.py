# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
a,b=map(int,input().split())
t=0
while a>0 and b>0:
	if a==1 and b==1:
		print(0)
		exit()
	x=min(a,b)
	if x==a:
		a+=1
		b-=2
	else:
		a-=2
		b+=1
	t+=1
print(t)