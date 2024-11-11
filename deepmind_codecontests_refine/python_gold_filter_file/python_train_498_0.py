from itertools import accumulate

h, w = map(int, input().split())
field = [input() for _ in range(h)]

l = max(h, w)
precalc_rd = []
precalc_ld = []
for ij in range(h + w - 1):
    coins = [0] * (l + 1)
    min_i = max(0, ij - w + 1)
    max_i = ij - max(0, ij - h + 1)
    offset = (min_i - (ij - min_i) + w - 1) // 2 + 1
    for d in range(max_i - min_i + 1):
        i = min_i + d
        j = ij - i
        if field[i][j] == '#':
            coins[offset + d] = 1
    precalc_ld.append(list(accumulate(coins)))

for ij in range(-w + 1, h):
    coins = [0] * (l + 1)
    min_i = max(0, ij)
    max_i = ij + min(w - 1, h - ij - 1)
    offset = (min_i + (min_i - ij)) // 2 + 1
    for d in range(max_i - min_i + 1):
        i = min_i + d
        j = i - ij
        if field[i][j] == '#':
            coins[offset + d] = 1
    precalc_rd.append(list(accumulate(coins)))

ans = 0

for ij in range(h + w - 1):
    min_i = max(0, ij - w + 1)
    max_i = ij - max(0, ij - h + 1)
    offset = (min_i - (ij - min_i) + w - 1) // 2 + 1
    for sd in range(max_i - min_i + 1):
        si = min_i + sd
        sj = ij - si
        if field[si][sj] == '.':
            continue
        for td in range(sd + 1, max_i - min_i + 1):
            ti = min_i + td
            tj = ij - ti
            if field[ti][tj] == '.':
                continue
            dij = (td - sd) * 2
            if ij - dij >= 0:
                ans += precalc_ld[ij - dij][offset + td - 1] - precalc_ld[ij - dij][offset + sd - 1]
            if ij + dij <= h + w - 2:
                ans += precalc_ld[ij + dij][offset + td] - precalc_ld[ij + dij][offset + sd]

for ij in range(-w + 1, h):
    min_i = max(0, ij)
    max_i = ij + min(w - 1, h - ij - 1)
    offset = (min_i + (min_i - ij)) // 2 + 1
    for sd in range(max_i - min_i + 1):
        si = min_i + sd
        sj = si - ij
        if field[si][sj] == '.':
            continue
        for td in range(sd + 1, max_i - min_i + 1):
            ti = min_i + td
            tj = ti - ij
            if field[ti][tj] == '.':
                continue
            dij = (td - sd) * 2
            if ij - dij + w - 1 >= 0:
                ans += precalc_rd[ij - dij + w - 1][offset + td] - precalc_rd[ij - dij + w - 1][offset + sd]
            if ij + dij + w - 1 <= h + w - 2:
                ans += precalc_rd[ij + dij + w - 1][offset + td - 1] - precalc_rd[ij + dij + w - 1][offset + sd - 1]

print(ans)
