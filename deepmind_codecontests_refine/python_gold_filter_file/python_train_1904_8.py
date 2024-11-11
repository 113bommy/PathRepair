import sys, collections
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    if sum(a) == m:
        print("YES")
    else:
        print("NO")


