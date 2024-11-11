import math
n,k=map(int,input().split())
a,b=map(int,input().split())
reqmin,reqmax=n*k,0
def calc(start):
    global reqmin,reqmax
    for i in range(0,n*k+1,k):
        for j in range(-1,2,2):
            if(start<i+j*b):
                l=i+j*b-start
                lcm=(l*n*k)/math.gcd(l,n*k)
                reqmin=min(reqmin,lcm/l)
                reqmax=max(reqmax,lcm/l)
                
calc(a)
calc(k-a)
print(round(reqmin),round(reqmax))
