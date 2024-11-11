import sys,collections
input=sys.stdin.readline
for _ in range(int(input())):
    N=int(input());check=True
    A=list(map(int,input().split()))
    D=dict()
    for i in range(N):
        C=(i+A[i])%N
        if C in D:
            check=False
            break
        else:
            D[C]=1
    if not check:
        print("NO")
    else:
        print("YES")