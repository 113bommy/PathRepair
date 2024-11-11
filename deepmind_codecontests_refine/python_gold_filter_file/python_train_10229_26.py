t = int(input())
for test in range(t):
    a,b,n = [int(x) for x in input().split()]

    op = 0
    a,b = min(a,b),max(a,b)
    mode = 0
    while a<=n and b<=n:
        op+=1
        if mode==0:
            a+=b
            mode=1
        else:
            b+=a
            mode=0
    print(op)