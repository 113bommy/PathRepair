import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))

    B=[(i+A[i])%n for i in range(n)]
    #print(B)

    if len(set(B))==n:
        print("YES")
    else:
        print("NO")
