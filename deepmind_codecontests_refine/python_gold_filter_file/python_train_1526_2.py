import sys 

I=sys.stdin.readline

n,a,b=map(int,I().split())
rou=1
while n>0:
	a-=1
	b-=1
	a=int(a/2)+1
	b=int(b/2)+1
	if a==b:
		if n==2:
			print("Final!")
		else:
			print(rou)
		break
	rou+=1
	n=n//2



