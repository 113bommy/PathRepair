t=int(input())
for k in range(t):
    a,b,n=list(map(int,input().split(" ")))
    c=0
    while a<=n and b<=n:
        c+=1
        if a>b:
            b+=a
        else:
            a+=b
    print(c)
