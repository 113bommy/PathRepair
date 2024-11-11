x,y,a,b=map(int,input().split())
def gcd(x,y):
    if(y==0):
        return x
    else:
        return gcd(y,x%y)
l=(x*y)//gcd(x,y)
k=(b-a)//l
if(b%l==0 or a%l==0):
    print(k+1)
else:
    print(b//l-a//l)