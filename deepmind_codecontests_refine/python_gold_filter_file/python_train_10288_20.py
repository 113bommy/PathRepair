n = int(input())
P = []
for _ in range(n):
  x, y, h = map(int, input().split())
  P.append([h, x, y])
P.sort(reverse=True)

for cx in range(101):
  for cy in range(101):
    H = P[0][0] + abs(P[0][1]-cx) + abs(P[0][2]-cy)
    for i in range(1,n):
      if max(H-abs(P[i][1]-cx)-abs(P[i][2]-cy), 0) != P[i][0]:
        break
    else:
      print(cx, cy, H)
      exit()