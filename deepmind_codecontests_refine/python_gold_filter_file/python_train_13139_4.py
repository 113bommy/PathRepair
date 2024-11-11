ans = 0
n, q = map(int, input().split())

# init
line = [[False, False] for _ in range(n)]

for idx in range(q):
    r, c = map(int, input().split())
    # set status
    r -= 1
    c -= 1
    if line[c][r]:
        flag = -1
        line[c][r] = False
    else:
        flag = 1
        line[c][r] = True
    # check
    r = 0 if r else 1
    if c - 1 >= 0 and line[c - 1][r]:
        ans += flag
    if c + 1 < n and line[c + 1][r]:
        ans += flag
    if line[c][r]:
        ans += flag
    # output result
    if ans:
        print('No')
    else:
        print('Yes')