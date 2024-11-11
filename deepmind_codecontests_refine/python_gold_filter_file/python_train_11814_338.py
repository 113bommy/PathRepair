m,n=map(int,input().split())
x=0
m,n=max(m,n),min(m,n)
if m%2==1 and n!=1:
    x+=int(n/2)
    x+=int(m/2)*n
else:
    x+=int(m/2)*n
print(x)