H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

l = []
for y in range(H):
    l += [(x, y) for x in list(range(W))[::-1 if y%2 else 1]]

p = []
for i, (x, y) in enumerate(l[:-1]):
    if A[y][x] % 2 == 0:
        continue
    nx, ny = l[i+1]
    p.append((x+1, y+1, nx+1, ny+1))
    A[y][x] -= 1
    A[ny][nx] += 1

print(len(p))
[print(*p_i[::-1]) for p_i in p]
