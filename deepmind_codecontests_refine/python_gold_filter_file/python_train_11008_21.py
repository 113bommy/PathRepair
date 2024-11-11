n=int(input())
a=b=c=d=e=0
while(n>=1):
    if (n>=100):
        a=n//100
        n-=100*a
    elif (n>=20):
        c=n//20
        n-=20*c
    elif (n>=10):
        d=n//10
        n-=10*d
    elif (n>=5):
        b=n//5
        n-=5*b
    else:
        e=n
        n-=e
print(a+b+c+d+e)
