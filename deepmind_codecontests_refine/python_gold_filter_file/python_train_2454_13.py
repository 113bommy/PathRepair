a=int(input())
b=int(input())
c=int(input())
maxim=0
for i in range(1,a+1):
	if i*2<=b and i*4<=c:
		maxim=i
print(7*maxim)
