x, y, n=map(int,input().split())
a=(x//n)+(y//n)
b=(x+y)//n
if a==b:
    print(a,0)
else:
    m1=x%n
    m2=y%n
    print(b,end=" ")
    if n-m1<n-m2:
        print(n-m1)
    else:
        print(n-m2)
    