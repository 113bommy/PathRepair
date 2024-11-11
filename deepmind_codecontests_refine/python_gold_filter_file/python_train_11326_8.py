H, W, A, B = map(int, input().split())

hbar = H - B
wbar = W - A

s = '0' * A + '1' * wbar
sbar = '1' * A + '0' * wbar
for i in range(B):
  print(s)
for i in range(hbar):
  print(sbar)