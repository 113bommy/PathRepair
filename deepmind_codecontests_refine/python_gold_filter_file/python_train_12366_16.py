h, w, k = map(int, input().split())
s = []
for _ in range(h):
    s.append(input())

sum = [[0] * (w+1) for _ in range(h+1)]
for i in range(h):
    for j in range(w):
        sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (1 if s[i][j] == '1' else 0)

ans = h + w - 2
for ptn in range(1<<h-1):
    cand = 0

    sep = [0]
    for i in range(h-1):
        if((ptn >> i) & 1):
            sep.append(i+1)
            cand += 1
    sep.append(h)

    left = 0
    for pos in range(w):
        cur = []
        for i in range(len(sep)-1):
            cur.append(sum[sep[i+1]][pos+1] - sum[sep[i+1]][left] - sum[sep[i]][pos+1] + sum[sep[i]][left])
        if max(cur) > k:
            if left == pos:
                cand = h * w
                break
            else:
                cand += 1
                left = pos
    ans = cand if cand < ans else ans

print(ans)
