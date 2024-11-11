import math


def pf(n):
    l=[]
    # no of even divisibility
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    # n reduces to become odd
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n
        while n % i == 0:
            l.append(i)
            n = n / i
    # if n is a prime
    if n > 2:
        l.append(n)
    return l


n,k=map(int,input().split())
fac=sorted(pf(n))
#print(fac)
if k==1:
    print(n)
else:
    if len(fac) <k:
        print(-1)
    else:
        ans=[]
        s=1
        ch=1
        for i in range(k-1):
            if i==len(fac)+1:
                ch=0
                print(-1)
            else:
                s=s*fac[i]
                ans.append(fac[i])
        ans.append(n//s)
        if ch:
            print(*ans)        
    