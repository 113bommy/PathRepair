#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
field = []
visited = [[False] * (m+2) for _ in range(n+2)]
field.append("$" * (m + 2))
has_blank_row = False
has_blank_col = False
for _ in range(n):
    row = input().rstrip()
    field.append("$" + row + "$")
    if "#" not in row:
        has_blank_row = True
field.append("$" * (m + 2))
for col in zip(*field):
    if "#" not in col[1:-1] and "$" not in col[1:-1]:
        has_blank_col = True
if has_blank_col ^ has_blank_row:
    print(-1)
    exit()

usedx = set()
usedy = set()
def convex_bfs(x, y):
    st = []
    to_be_usedx = set()
    to_be_usedy = set()
    visited[x][y] = True
    st.append((x, y))
    colmin = [n+1] * (m + 1)
    colmax = [-1] * (m + 1)
    colcnt = [0] * (m + 1)
    rowmin = [m+1] * (n + 1)
    rowmax = [-1] * (n + 1)
    rowcnt = [0] * (n + 1)
    while st:
        x, y = st.pop()
        if x < colmin[y]:
            colmin[y] = x
        if x > colmax[y]:
            colmax[y] = x
        colcnt[y] += 1
        if y < rowmin[x]:
            rowmin[x] = y
        if y > rowmax[x]:
            rowmax[x] = y
        rowcnt[x] += 1
        to_be_usedx.add(x)
        to_be_usedy.add(y)
        if x in usedx or y in usedy:
            print(-1)
            exit()
        if field[x + 1][y] == "#" and not visited[x + 1][y]:
            st.append((x + 1, y))
            visited[x + 1][y] = True
        if field[x - 1][y] == "#" and not visited[x - 1][y]:
            st.append((x - 1, y))
            visited[x - 1][y] = True
        if field[x][y + 1] == "#" and not visited[x][y + 1]:
            st.append((x, y + 1))
            visited[x][y + 1] = True
        if field[x][y - 1] == "#" and not visited[x][y - 1]:
            st.append((x, y - 1))
            visited[x][y - 1] = True
    for rc, rmin, rmax in zip(rowcnt, rowmin, rowmax):
        if rc == 0:
            continue
        if rc != rmax - rmin + 1:
            print(-1)
            exit()
    for cc, cmin, cmax in zip(colcnt, colmin, colmax):
        if cc == 0:
            continue
        if cc != cmax - cmin + 1:
            print(-1)
            exit()
    return to_be_usedx, to_be_usedy

ans = 0
for i in range(1, n+1):
    for j in range(1, m+1):
        if field[i][j] == "#" and visited[i][j] == False:
            to_be_usedx, to_be_usedy = convex_bfs(i, j)
            usedx.update(to_be_usedx)
            usedy.update(to_be_usedy)
            ans += 1
print(ans)