from random import randint
from math import gcd
def pal(x):
    p=False
    a = randint(2, x - 1)
    if gcd(a,x)==1:
        if a**(x-1)%x==1:
                p=True
        else:
            return False
    return p


t = int(input())
for q in range(t):
    n = int(input())
    dn = input().split(' ')
    d = [int(n) for n in dn]
    d.sort()
    p = d[-1] * d[0]
    ct = 0
    neg1=False
    
    if n==1 and d[0]>=10**3 :
        print(p)
        neg1=True
        
    elif n<=6:
        for i in range(2, p):
            if p % i == 0:
                ct += 1
            if ct > n:
                print(-1)
                neg1 = True
                break
            elif ct==0 and i==5:
                break
                if pal(d[0]):
                    print(-1)
                    neg=True
                    break


            
    if not(neg1):
        for i in range(n//2 +1):
            if not (d[i] * d[-1 - i] == p):
                neg1=True
                print(-1)
                break
    
    i=0
    if not(neg1):
        while i < len(d):
            if d[i]!=d[-1] and d[i]!=d[0] and not (p % d[i] == 0):
                i = 0
                d = d[:-1]
                p = d[-1] * d[0]
            i+=1
        
        print(p)       
            

        


    













