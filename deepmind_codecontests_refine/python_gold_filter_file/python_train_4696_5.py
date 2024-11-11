arr=list(map(int,input().split()))
a=arr[0]
b=arr[1]
x=arr[2]
y=arr[3]
def gcd(l,m):
    if l%m==0:
        return m
    return gcd(m,l%m)
xygcd=gcd(max(x,y),min(x,y))
x=x//xygcd
y=y//xygcd
print(min(a//x,b//y)) 
