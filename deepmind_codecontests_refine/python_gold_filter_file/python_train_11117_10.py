N,M=map(int,input().split())
L=[0]*N
A=0
W=0
tmp=[0]*N
for i in range(M):
	x,y=input().split()
	t=int(x)
	if L[t-1]==0:
		if y=="WA":
			tmp[t-1]+=1
		else:
			A+=1
			W+=tmp[t-1]
			L[t-1]=1
print(A,W)