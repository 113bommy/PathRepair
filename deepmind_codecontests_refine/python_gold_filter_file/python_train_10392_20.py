N = int(input())
Point = [list(map(int, input().split())) for i in range(N)]


# 各点の原点からのマンハッタン距離の偶奇は一致していなければならない
if len(set([(abs(x) + abs(y)) % 2 for x, y in Point])) == 2:
    print(-1)
    exit()


# 2べきの腕を構成
Arms = [2 ** i for i in reversed(range(39))]

# 偶数に合わせたい場合は長さ1の腕を追加
if (abs(Point[0][0]) + abs(Point[0][1])) % 2 == 0:
    Arms.append(1)


# Arm部の答えを出力
print(len(Arms))
print(' '.join(map(str, Arms)))


# 各点に到達するための腕の決める
for x, y in Point:
    ans = ''
    for length in Arms:
        min_diff, tmp_s = float('inf'), ''
        next_x, next_y = None, None
        for order, dx, dy in (('L', 1, 0), ('R', -1, 0), ('D', 0, 1), ('U', 0, -1)):
            tmp_x, tmp_y = (x + length * dx), (y + length * dy)
            diff = abs(tmp_x) + abs(tmp_y)

            if diff < min_diff:
                min_diff = diff
                tmp_s = order
                next_x, next_y = tmp_x, tmp_y

        ans += tmp_s
        x, y = next_x, next_y
    print(ans)
