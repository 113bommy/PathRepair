import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n, vals, ans, x = int(input()), sorted([int(i) for i in input().split()]), [], None
    if n % 2:
        x, n = vals.pop(), n - 1
    l, r = n // 2 - 1, n // 2
    for i in range(n // 2):
        ans.append(vals[r])
        ans.append(vals[l])
        r, l = r + 1, l - 1
    if x != None:
        ans.append(x)
    print(*ans)