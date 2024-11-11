import sys
input = sys.stdin.readline
from bisect import bisect
N=int(input())
X=[int(i) for i in input().split()]
L=int(input())
Q=int(input())
#T=[[int(i) for i in input().split()] for i in range(Q)]
T=[]
for i in range(Q):
    a,b=map(int,input().split())
    if a>b:
        a,b=b,a
    T.append((a-1,b-1))
F=[0]*N
for i in range(N):
    F[i]= bisect(X, X[i] + L) -1
#print(F)
dp=[ [N-1] * (N) for i in range(18)]

for i in range(N):
    #dp[0][i]=i
    dp[0][i]=F[i]
for c in range(1,18):
    for i in range(N):
        dp[c][i] = dp[c-1][ dp[c-1][i] ]
#print(dp)

def f(a,b):
    num=0
    t = a
    while True:
        for i in range(18):
            if dp[i][t]>=b:
                s=i
                break
        if s==0:
            num+=1
            break
        num += pow(2, s - 1)
        t = dp[s-1][t]
    print(num)
for a,b in T:
    f(a,b)

