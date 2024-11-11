import math
n=int(input())
s=int(input())

def f(b,n):
    m=math.floor(n/b)
    if n>=b:
        return f(b,m) + n%b
    else:
        return n

if n<s:
    print(-1)
elif n==s:
    print(n+1)
else:
    for i in range(2,int(math.sqrt(n))+1):
        if f(i,n)==s:
            print(i)
            break
    else:
        for p in range(int(math.sqrt(n)),0,-1):
            if (n-s)%p==0:
                b=(n-s)//p+1
                #print(b)
                #print(f(b,n))
                if f(b,n)==s:
                    print(b)
                    break
        else:
            print(-1)