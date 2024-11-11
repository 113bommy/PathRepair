T = int(input())
while T:
    N = int(input())
    if N>0:
        print(-(N-1),N)
    elif N<0:
        print(N,-(N+1))
    else:
        print(0)
    T-=1