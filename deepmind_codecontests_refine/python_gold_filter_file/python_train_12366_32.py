H, W, K = map(int, input().split())
choco = [list(map(int, list(input().strip()))) for i in range(H)]

ans = (H-1) * (W-1)

for i in range(2**(H-1)):
    cut = 0

    yoko = [choco[0]]
    for j in range(H-1):
        if (i>>j) & 1 == 1:
            # 折った
            cut += 1
            yoko.append(choco[j+1])
        else:
            # 折らない -> まとめる
            yoko[-1] = [a + b for a, b in zip(yoko[-1], choco[j+1])]

    count = [yoko[i][0] for i in range(cut+1)]

    if max(count) > K:
        continue

    for x in range(1, W):
        now_count = [yoko[y][x] for y in range(len(count))]
        next_count = [a + b for a, b in zip(now_count, count)]
        if max(next_count) > K:
            # 折る
            count = now_count
            cut += 1
        else:
            # 折らない
            count = next_count

    ans = min(ans, cut)

print(ans)