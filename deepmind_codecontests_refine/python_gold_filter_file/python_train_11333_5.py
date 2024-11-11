W, H = (int(i) for i in input().split())
L = []
for i in range(W):
  L.append((int(input()), 0))
for i in range(H):
  L.append((int(input()), 1))
a = W
b = H
ans = 0
L.sort()
for i in range(H + W):
  if L[i][1] == 0:
    ans += (b+1) * L[i][0]
    a -= 1
  else:
    ans += (a+1) * L[i][0]
    b -= 1
print(ans)