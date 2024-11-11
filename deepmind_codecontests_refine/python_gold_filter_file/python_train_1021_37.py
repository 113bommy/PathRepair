h, w = [int(i) for i in input().split()]
s = [list(input()) for _ in range(h)]
flg = True

for i in range(1, h - 1):
    for j in range(1, w - 1):
        if s[i][j] == "#" and s[i - 1][j] == "." and s[i + 1][j] == "." and s[i][j - 1] == "." and s[i][j + 1] == ".":
            flg = False

print('Yes' if flg else 'No')
