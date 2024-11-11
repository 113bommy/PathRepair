T=int(input())
for _ in range(T):
    N=int(input())
    A=list(map(int,input().split()))
    if A[1]+A[0]<=A[-1]:
        print(1,2,N)
    else:
        print(-1)
