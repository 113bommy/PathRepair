t=int(input())
import math
while t:
    t-=1

    n,m=list(map(int,input().split()))
    '''if n==1 and m==1:
        print(1)
        continue
    if n==1 or m==1:
        print(max(n,m)-1)
        continue
    if (not n&1) or (not m&1):
        print((n*m)//2)
        continue'''
    print(((((n-1)*m)//2)+math.ceil(m/2)))

    '''if n<m:
        print(((((n-1)*m)//2)+math.floor(n/2)))
        continue
    elif n>m:
        print(((((m-1)*n)//2)+m))
    else:
        print(((((n-1)*m)//2)+n-1))'''