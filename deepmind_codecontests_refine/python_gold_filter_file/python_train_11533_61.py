def zero_origin(s: str) -> int:
  return int(s) - 1

h, w = map(int, input().split())
ch, cw = map(zero_origin, input().split())
dh, dw = map(zero_origin, input().split())
s = [input() for _ in range(h)]
active = [
  [True if s[i][j] == '.' else False for j in range(w)]
  for i in range(h)]

magic = 0
stack = [(ch, cw)]
active[ch][cw] = False
visited = []
while stack:
  cur_i, cur_j = stack.pop()
  visited.append((cur_i, cur_j))
  for di, dj in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
    i = cur_i + di
    j = cur_j + dj
    if 0 <= i < h and 0 <= j < w and active[i][j]:
      stack.append((i, j))
      active[i][j] = False
  if not active[dh][dw]:
    print(magic)
    break
  if not stack:
    magic += 1
    while visited:
      cur_i, cur_j = visited.pop()
      for i in range(cur_i - 2, cur_i + 3):
        for j in range(cur_j - 2, cur_j + 3):
          if 0 <= i < h and 0 <= j < w and active[i][j]:
            stack.append((i, j))
            active[i][j] = False
else:
  print(-1)