x,y,a,b=map(int,input().split())

def gcd(x,y):
    if (x%y==0):
        return y
    else:
        return(gcd(y,x%y))

n=gcd(x,y)
t=x*y/n
s=0
u=(int(a/t)+1)*t

if(u<b):s=int((b-u)/t)+1
if a%t==0:s+=1


print(s)

        
    
