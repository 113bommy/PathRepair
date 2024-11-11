n,d=map(int,input().split())
d=d*d
count=0
for _ in range(n):
	x,y=map(int,input().split())
	if(x*x+y*y<=d):
		count+=1
print(count)