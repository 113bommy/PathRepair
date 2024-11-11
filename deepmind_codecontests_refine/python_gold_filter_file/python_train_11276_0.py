import sys
input = sys.stdin.readline

n,m,k=map(int,input().split())
YOKO=[list(map(int,input().split())) for i in range(n)]
TATE=[list(map(int,input().split())) for i in range(n-1)]

if k%2==1:
    for i in range(n):
        print(*[-1]*m)
    exit()

DP=[[0]*m for i in range(n)]

for i in range(n):
    for j in range(m):

        MIN=1<<30

        if j-1>=0:
            MIN=min(MIN,YOKO[i][j-1]*2)
        if j<m-1:
            MIN=min(MIN,YOKO[i][j]*2)

        if i-1>=0:
            MIN=min(MIN,TATE[i-1][j]*2)
        if i<n-1:
            MIN=min(MIN,TATE[i][j]*2)

        DP[i][j]=MIN

DP0=DP[:]
#print(DP)

for tests in range(k//2-1):
    NDP=[[0]*m for i in range(n)]

    for i in range(n):
        for j in range(m):
            MIN=DP[i][j]+DP0[i][j]

            if 0<=i+1<n:
                MIN=min(MIN,TATE[i][j]*2+DP[i+1][j])

            if 0<=i-1<n:
                MIN=min(MIN,TATE[i-1][j]*2+DP[i-1][j])

            if 0<=j+1<m:
                MIN=min(MIN,YOKO[i][j]*2+DP[i][j+1])

            if 0<=j-1<m:
                MIN=min(MIN,YOKO[i][j-1]*2+DP[i][j-1])

            NDP[i][j]=MIN
    DP=NDP

for dp in DP:
    print(*dp)
        

