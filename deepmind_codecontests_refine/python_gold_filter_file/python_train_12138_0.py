n, m = map(int, input().split())
cells = [list(input()) for _ in range(n)]
ans = 'NO'
for r in range(n):
    for c in range(m):
        if cells[r][c] == "S":
            sr, sc = r, c
        elif cells[r][c] == "T":
            tr, tc = r, c

for cc in range(m):
    if ans == 'YES':
        break
    f = True
    for c in range(min(cc, sc), max(cc, sc) + 1):
        if cells[sr][c] == '*':
            f = False
            break
    for r in range(min(sr, tr), max(sr, tr) + 1):
        if cells[r][cc] == '*':
            f = False
            break
    for c in range(min(cc, tc), max(cc, tc) + 1):
        if cells[tr][c] == '*':
            f = False
            break
    if f:
        ans = 'YES'

for cr in range(n):
    if ans == 'YES':
        break
    f = True
    for r in range(min(cr, sr), max(cr, sr) + 1):
        if cells[r][sc] == '*':
            f = False
            break
    for c in range(min(sc, tc), max(sc, tc) + 1):
        if cells[cr][c] == '*':
            f = False
            break
    for r in range(min(cr, tr), max(cr, tr) + 1):
        if cells[r][tc] == '*':
            f = False
            break
    if f:
        ans = 'YES'

print(ans)
