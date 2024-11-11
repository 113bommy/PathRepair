A,B =[int(x) for x in input().split()]
a=1
for i in range(1,min(A,B)+1):
	a*=i
print(a)