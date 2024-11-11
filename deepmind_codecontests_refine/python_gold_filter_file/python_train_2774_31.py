import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[ ]
if n==0:
    print(a.index(min(a))+1,0)
else:
    for i in a:
        b.append(n%i)
    a1=b.index(min(b))
    print(a1+1,n//a[a1])