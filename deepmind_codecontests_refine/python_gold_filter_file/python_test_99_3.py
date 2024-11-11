import sys
input = lambda:sys.stdin.readline().strip()
t = int(input())
while t:
    t-=1
    x0,n = map(int,input().split())
    if n%4==0:
        print(x0)
    elif n%4==1:
        if x0&1:
            print(x0+(n))
        else:
            print(x0-(n))
    elif n%4==2:
        if x0&1:
            print(x0-1)
        else:
            print(x0+1)
    else:
        if x0&1:
            print(x0-(n+1))
        else:
            print(x0+(n+1))