n=int(input())
t1=0
t2=0
s1=0
s2=0
for i in range(n):
	a=list(map(int,input().split()))
	if a[0]==1:
		t1=t1+1
		s1=s1+a[1]
	else:
		t2=t2+1
		s2=s2+a[1]		
if 2*s1>=t1*10:
	print("LIVE")
else:
	print("DEAD")
if 2*s2>=t2*10:
	print("LIVE")
else:
	print("DEAD")