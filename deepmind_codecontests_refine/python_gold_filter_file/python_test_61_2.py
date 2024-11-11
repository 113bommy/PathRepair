def solve():
    n = int(input())
    arr = [list(map(int, input().split())) for i in range(n)]
    a = [-1] * (n+1)
    b = [-1] * (n+1)
    for i in range(n):
        a[arr[i][0]] += 1
        b[arr[i][1]] += 1
    ans = 0
    for x, y in arr:
        ans += a[x] * b[y]
    return n*(n-1)*(n-2)//6 - ans


import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for i in range(t):
    print(solve())
