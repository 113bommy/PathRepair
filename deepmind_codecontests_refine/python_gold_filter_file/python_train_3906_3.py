a,b=list(map(int,input().split()))
c=[b]
for i in range(a):
	e,f=list(map(int,input().split()))
	c+=[e+f]
print(max(c))