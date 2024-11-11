from  fractions import Fraction
from math import gcd
n,m,q=list(map(int,input().split()))
if  gcd(n,m)>1 :
    #a/n=b/m , n/m=a/b
    #k=Fraction(n,m)
    #num=k.numerator
    #den=k.denominator
    x=gcd(n,m)
    for ad in range(q):
        a,b,c,d=list(map(int,input().split()))
        if a==1:
            e=n
        else:
            e=m
        if c==1:
            f=n
        else:
            f=m
        if True:
            #print((b-1)//(e//x),(d-1)//(f//x))
            if (b-1)//(e//x)==(d-1)//(f//x):
                print("YES")
            else:
                print("NO")

else:

    for i in range(q):
        a, b, c, d = list(map(int, input().split()))
        if a == 1:
            e = n
        else:
            e = m
        if c == 1:
            f = n
        else:
            f = m
        if (b-1)//e>(d-1)//f:
            print("NO")
        else:
            print("YES")

