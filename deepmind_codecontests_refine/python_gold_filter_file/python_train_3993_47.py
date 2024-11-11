n,m,a=input().split()
n=int(n)
m=int(m)
a=int(a)
if (n%a==0):
    x=n/a
else:
    x=(n//a)+1
if (m%a==0):
    y=(m/a)
else:
    y=(m//a)+1
print(int(x*y))    