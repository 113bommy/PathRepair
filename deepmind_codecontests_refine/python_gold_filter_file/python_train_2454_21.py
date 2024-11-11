# https://codeforces.com/problemset/problem/746/A

a = int(input())
b = int(input())
c = int(input())

ans = min(a // 1, b // 2, c // 4)

print(1 * ans + 2 * ans + 4 * ans)
