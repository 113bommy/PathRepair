n,x,y=input().split()
n=int(n)
x=int(x)
y=int(y)

l=[int(x) for x in input().split()]

l.sort()

count_a=0


for i in range(n):
	if(l[i]<=x):
		count_a+=1

if(x>y):
	print(n)

else:
	print((count_a%2)+(count_a//2))




