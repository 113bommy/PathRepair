n,k=map(int,input().split())
if k==n or k==0:print(0,0)
elif k<=(n)//3:print(1,k*2)
else:print(1,n-k)
