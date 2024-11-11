for _ in range(int(input())):
    n,m,rb,cb,rd,cd=list(map(int,input().split()))
    row=1
    col=1
    ans=0
    while rb!=rd and cb!=cd:
        if rb==n:
            row = -1
        if cb==m:
            col = -1
        rb,cb= rb+row,cb+col
        ans+=1
    print(ans)