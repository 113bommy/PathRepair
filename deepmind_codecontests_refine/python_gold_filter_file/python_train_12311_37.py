import sys

input = lambda: sys.stdin.readline().strip("\r\n")

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    ans = [-1, -1]
    if c > a:
        ans[0] = 1
    if a * b > c:
        ans[1] = b
    print(*ans)
