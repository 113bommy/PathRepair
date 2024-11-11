for _ in range(int(input())):
    N=int(input())
    A=list(map(int,input().split()))
    if(len(set(A))==1):
        print(N)
    else:
        print(1)