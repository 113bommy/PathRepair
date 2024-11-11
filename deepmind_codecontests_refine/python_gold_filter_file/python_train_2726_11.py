# t = int(input())
# ans = list()
# for _ in [0] * t:
#     n, r = map(int, input().split())
#     x = sorted(set(map(int, input().split())))[::-1]
#     ans.append(sum([x - i * r > 0 for i, x in enumerate(x)]))
# print(' '.join(map(str, ans)))


# n = int(input())
# dots = []
# for i in range(n):
#     dots.append(sum(list(map(int, input().split()))))
# print(max(dots))


# n, m = map(int, input().split())
# print(pow(2**m - 1, n, 10**9 + 7))


# n, k = map(int, input().split())
# s = input()
# if not k:
#     print(s)
# elif n == 1:
#     print('0')
# else:
#     s = [int(i) for i in s]
#     if s[0] > 1:
#         s[0], k = 1, k - 1
#     for i in range(1, n):
#         if not k:
#             break
#         if s[i] > 0:
#             s[i], k = 0, k - 1
#     print(''.join(map(str, s))) if len(s) > 1 else print('0')


m, n = map(int, input().split())
r = list(map(int, input().split()))
c = list(map(int, input().split()))
grid = [['ok'] * (n + 1) for i in range(m + 1)]

for i in range(m):
    row = r[i]
    if row:
        for j in range(row):
            grid[i][j] = 1
        grid[i][row] = 0
    else:
        grid[i][row] = 0


inv = False
for j in range(n):
    col = c[j]
    if col:
        for i in range(col):
            if grid[i][j] == 0:
                inv = True
                break
            else:
                grid[i][j] = 1
        if grid[col][j] == 1:
            inv = True
            break
        else:
            grid[col][j] = 0
    else:
        if grid[col][j] == 1:
            inv = True
            break
        else:
            grid[col][j] = 0

if inv:
    print(0)
else:
    cnt = 0
    for row in grid[:m]:
        cnt += row[:n].count('ok')
    print(pow(2, cnt, 10**9 + 7))
