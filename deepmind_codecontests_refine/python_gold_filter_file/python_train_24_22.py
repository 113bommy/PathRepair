t=int(input())
for i in range(0,t):
    n = int(input())
    l = list(map(int,input().split()))
    a=l[0]
    c=l[n-1]
    b=False
    for i in range(1,n-1):
        if(a+l[i] <=c):
            b=i+1
            break
    if(b):
        print("1", b, n)
    else:
        print(-1)