t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    if b==a: print(0)
    elif b<a:
        if a%b!=0: print(-1)
        else:
            n=a//b
            i=0
            while n%(2**i)==0:
                i+=1
            if 2**(i-1)!=n: print(-1)
            elif (i-1)%3==0: print((i-1)//3)
            elif (i-1)%3!=0: print((i-1)//3 + 1)
    elif b>a:
        x=a
        a=b
        b=x
        if a%b!=0: print(-1)
        else:
            n=a//b
            i=0
            while n%(2**i)==0:
                i+=1
            if 2**(i-1)!=n: print(-1)
            elif (i-1)%3==0: print((i-1)//3)
            elif (i-1)%3!=0: print((i-1)//3 + 1)
