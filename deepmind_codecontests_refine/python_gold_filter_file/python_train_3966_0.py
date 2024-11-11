import math
n,k=map(int,input().split())
ans=0
for i in range(1,n+1):
    if (i%2==1):
        print("1",end="")
    else:
        print("0",end="")