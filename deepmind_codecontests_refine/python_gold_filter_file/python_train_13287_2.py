import sys
n,a,b=map(int,input().split())
x=0
for i in range(1,n):
    aa=a/i
    bb=b/(n-i)
    aa=int(aa)
    bb=int(bb)
    x=max(x,min(aa,bb))
print(x)

