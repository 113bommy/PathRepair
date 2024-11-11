
n=int(input())
for i in range(n):
	a,b=map(int,input().split())
	if abs(a-b)==1:
		x=a+b
		i=2
		f=0
		while i*i<=x:
			if x%i==0:
				f=1
				break
			i+=1
		if f:
			print("NO")
		else:
			print("YES")
	else:
		print("NO")