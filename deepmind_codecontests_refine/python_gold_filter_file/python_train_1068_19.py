import math
t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    A = list(map(int,input().split()))
    # print(len(set(A))-k+1)
    sb = len(set(A))
    if k==1:
        if sb==1:
            print(1)
        else:
            print(-1)
        continue
    print(1+max(0,math.ceil((sb-k)/(k-1))))