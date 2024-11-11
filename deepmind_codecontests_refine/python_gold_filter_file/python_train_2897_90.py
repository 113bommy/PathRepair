n = int(input())
s = [list(ord(e) - ord("a") for e in input()) for _ in range(n)]

ans = 0
for b in range(n):
    t = [[-1] * n for _ in range(n)]
    for hi in range(n):
        for wi in range(n):
            nh = hi
            nw = (wi + b) % n
            t[nh][nw] = s[hi][wi]

    bl = True
    for i in range(n):
        for j in range(n):
            if t[i][j] != t[j][i]:
                bl = False

    ans += bl

ans *= n
print(ans)
