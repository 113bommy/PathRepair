for tests in range(int(input())):
    N,x,y=map(int,input().split())
    maxR=min(x+y-1,N)
    if x+y<N+1:
        diff=N-1
    else:
        diff=2*N-x-y-1
    if diff>=N-1:
        print(1,maxR)
        continue
    print(min(N-diff,N),maxR)