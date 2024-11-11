import sys
l,r,k=map(int,input().split())
kk=1
while(l>kk):
	kk*=k
f=True;
while(kk<=r):
	print(kk, end=" ")
	f=False
	kk*=k
if f:
        print(-1)
