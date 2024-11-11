# ABC 109 D - Make Them Even

h, w = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(h)]

# 左上から一筆書きの経路を作成
step = []
for i in range(h):
  for j in range(w):
    if i % 2 == 0:
      step.append((i, j))
    else:
      step.append((i, w - j - 1))  
    
ans = []
for (a, b), (c, d) in zip(step, step[1:]):
  if A[a][b] % 2 == 1:
    A[c][d] += 1
    ans.append([a + 1, b + 1, c + 1, d + 1])

print(len(ans))
for a in ans:
  print(*a)