n=int(input())
x=0
i=0
while x<=n:
	x=i*(i+1)*(i+2)//6
	i+=1
print(i-2)