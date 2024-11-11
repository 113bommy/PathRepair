n,m,a=map(int,input().split())
if n%a==0:
    l=n//a
else:
    l=(n//a)+1
if m%a==0:
    b=m//a
else:
    b=(m//a)+1
print(l*b)