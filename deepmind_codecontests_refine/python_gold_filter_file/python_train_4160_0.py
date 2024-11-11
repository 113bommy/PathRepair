f=lambda A,x,B,C:(A*x+B)%C
while 1:
    N,A,B,C,X=map(int,input().split())
    if not N and not A and not B and not C and not X:break
    Y=list(map(int,input().split()))
    T=X
    c=[[] for _ in range(N)]

    sl=0
    for i in range(10005):
        if T==Y[sl]:
            sl+=1
            if sl==N:break
        T=f(A,T,B,C)
    if i>10000:i=-1
    print(i)

