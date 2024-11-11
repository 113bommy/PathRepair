H, W, N = map(int, input().split())
Sr, Sc = map(int, input().split())
S = input()
T = input()

# 左か上に移動させたい
now = [Sr, Sc]
for s, t in zip(S, T):
  # 高橋くんのターン
  if s == 'L':
    now[1] -= 1
  if s == 'U':
    now[0] -= 1
  # 駒を取り除けたかチェック
  if now[0] <= 0 or now[1] <= 0:
    print('NO')
    quit()
  
  # 青木くんのターン
  if t == 'R':
    now[1] = min(now[1] + 1, W)
  if t == 'D':
    now[0] = min(now[0] + 1, H)

# 右か下に移動させたい
now = [Sr, Sc]
for s, t in zip(S, T):
  # 高橋くんのターン
  if s == 'R':
    now[1] += 1
  if s == 'D':
    now[0] += 1
  # 駒を取り除けたかチェック
  if H < now[0] or W < now[1]:
    print('NO')
    quit()
  
  # 青木くんのターン
  if t == 'L':
    now[1] = max(now[1] - 1, 1)
  if t == 'U':
    now[0] = max(now[0] - 1, 1)

print('YES')