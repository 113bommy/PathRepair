import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if a[-1]>a[0]:
        print("YES")
    else:
        print("NO")