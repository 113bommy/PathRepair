n = int(input())
s = [list(input()) for _ in range(n)]
ans = 0
alphcnt = [0] * 26
for i in range(n):
    for j in range(n):
        alphcnt[ord(s[i][j]) - 97] += 1
if max(alphcnt) == pow(n, 2):
    print(pow(n, 2))
    exit()
for k in range(n):
    c = 1
    for i in range(n - 1):
        for j in range(i + 1, n):
            if not s[(i + k) % n][j] == s[(j + k) % n][i]:
                c = 0
                break
        if c == 0:
            break
    if c == 1:
        ans += n
print(ans)