import math
n=int(input())
#n,m = map(int, input().strip().split(' '))
#lst = list(map(int, input().strip().split(' ')))
k=int(input())
a=int(input())
b=int(input())
l=[]
a1=a*(n-1)
if k!=1 and k<=n:
    a2=0
    while(n!=1):
        if n%k==0:
            n=n//k
            a2+=b
            l.append(a2+(n-1)*a)
        else:
            if n>k:
                p=n%k
                a2+=p*a
                n-=p
                l.append(a2+(n-1)*a)
            else:
                a2+=(n-1)*a
                n=1
        
    print(min(a1,min(l),a2))
else:
    print(a1)

#1999888325
#2000000000 