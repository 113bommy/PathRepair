# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
n,k=map(int,input().split())
for i in range(n):
	x,y=map(int,input().split())
	if y>=k:
		if i==0:
			t=x-(y-k)
		else:
			t=max(t,x-(y-k))
	else:
		if i==0:
			t=x
		else:
			t=max(t,x)
print(t)
