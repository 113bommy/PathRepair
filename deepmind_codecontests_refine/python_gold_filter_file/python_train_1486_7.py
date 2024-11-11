# import sys
# input = sys.stdin.readline

n, m = map(int,input().split())
A = [list(map(int,list(input()))) for i in range(n)]

def diff3(X, i, j):
    if i==1 and j==1:
        k = [0,1,0]
    elif i==0 and j==1:
        k = [0,0,1]
    elif i==1 and j==0:
        k = [0,1,1]
    else:
        k = [0,0,0]
    dif = 0
    for ii in range(3):
        if X[ii] != k[ii]:
            dif += 1
    return min(dif, 3-dif)

if n == 1 or m == 1:
    print(0)
elif n >= 4 and m >= 4:
    print(-1)
elif n == 2 or m == 2:
    if m > n:
        m,n = n,m
        B = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                B[i][j] = A[j][i]
    else:
        B = A

    ans = float("inf")
    C = [sum(B[i])%2 for i in range(n)]

    ans0 = 0
    p = 0
    for i in range(n):
        if C[i]!=p:
            ans0 += 1
        p=(p+1)%2
    ans = min(ans,ans0)

    ans0 = 0
    p = 1
    for i in range(n):
        if C[i]!=p:
            ans0 += 1
        p=(p+1)%2
    ans = min(ans,ans0)

    print(ans)
else:
    # print("case3")
    if m > n:
        m,n = n,m
        B = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                B[i][j] = A[j][i]
    else:
        B = A

    # print(B)
    ans = float("inf")
    for i in range(2):
        for j in range(2):
            ans0 = 0
            ii=i
            jj=j
            for k in range(n):
                ans0 += diff3(B[k][:], ii, jj)
                ii=(ii+1)%2
                jj=(jj+1)%2
            ans = min(ans,ans0)

    print(ans)