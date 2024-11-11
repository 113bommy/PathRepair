def gcd(a,b):
    if a==0:
        return b
    return gcd(b%a,a)
    
a,b,x,y=map(int,str(input()).strip().split())
while(gcd(x,y)!=1):
    t=gcd(x,y)
    x//=t
    y//=t
r=a//x
p=b//y
print(min(r,p))