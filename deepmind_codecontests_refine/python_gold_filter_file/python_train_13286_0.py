import math

nk=input().split()
n=int(nk[0])
k=int(nk[1])
L=[0]*5
L[1]=1
L[2]=(n*(n-1))//2
L[3]=(n*(n-1)*(n-2))//3
L[4]=(3*n*(n-1)*(n-2)*(n-3))//8
s=0
for i in range(0,k+1):
	s+=L[i]
print(s)


