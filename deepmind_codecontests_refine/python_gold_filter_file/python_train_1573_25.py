n=int(input())
tavantwo=[0]*50
tavantwo[0]=1
h=0
for i in range(1,32):
	tavantwo[i]=tavantwo[i-1]*2
for i in range(32):
	if n<=tavantwo[i]-1:
		h=i
		break
print(h)
