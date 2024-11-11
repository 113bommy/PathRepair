b=int(input())
g=int(input())
n=int(input())
m=min(b,g)
M=max(b,g)
o=min(n+1,m+1)
q=min(n-M,m)


if b>=n and g>=n:
    print (n+1)
elif M>=n:
    print (o)
else:
    print(m-q+1)