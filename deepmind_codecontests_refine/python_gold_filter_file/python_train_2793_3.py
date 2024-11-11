import math
K = int(input())
A = list(map(int,input().split()))
if A[K-1]!=2:
    print(-1)
elif K==1:
    print(2,3)
else:
    nmin = 2
    nmax = 2+A[K-1]-1
    flag = 0
    for i in range(K-2,-1,-1):
        b = A[i]
        nmin = math.ceil(nmin/b)*b
        nmax = math.floor(nmax/b)*b
        if nmin>nmax:
            flag = 1
            break
        nmax += b-1
    if flag==1:
        print(-1)
    else:
        print(nmin,nmax)