import sys
import math
read = lambda: list(map(int, sys.stdin.readline().strip().split()))

for _ in range(int(input())):
    n, x = read()
    a = read()
    a.sort()
    ans = -1
    for i in range(n-1, -1, -1):
        if a[i] > x:
            ans = 2
        elif a[i] == x:
            ans = 1
        else:
            break
    if ans == -1:
        ans = (math.ceil(x/a[n-1]))
    print(ans)




























