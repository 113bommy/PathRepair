from math import ceil,sqrt,gcd
def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().strip().split(" "))
def li(): return list(mi())
t2=ii()
while(t2):
    t2-=1
    n,m=mi()
    f=0
    l1=m
    h1=m
    t1=0
    for i in range(n):
        t,l,h=mi()
        x=(t-t1)
        t1=t
        l1-=x
        h1+=x
        if(l1>=l and l1<=h):
            f1=1
        elif(h1>=l and h1<=h):
            f1=1
        elif(l>=l1 and l<=h1):
            f1=1
        elif(h>=l1 and h<=h1):
            f1=1
        else:
            f=1
        l1=max(l,l1)
        h1=min(h,h1)
    if(f==0):
        print('YES')
    else:
        print('NO')
    