H, W = map(int, input().split())
ns = {}
for i in range(H):
  As = input()
  for a in As:
    if a not in ns: ns[a] = 0
    ns[a] += 1
ns4 = [0, 0, 0, 0]
for a in ns:
  n = ns[a]
  ns4[n%4] += 1
#print(ns4)
if H%2 == 0 and W%2 == 0:
  if ns4[1] > 0 or ns4[2] > 0 or ns4[3] > 0:
    print("No")
  else:
    print("Yes")
if H%2 == 1 and W%2 == 0:
  if ns4[1]+ns4[3] > 0:
    print("No")
  elif ns4[2] > W//2:
    print("No")
  else:
    print("Yes")
if H%2 == 0 and W%2 == 1:
  if ns4[1]+ns4[3] > 0:
    print("No")
  elif ns4[2] > H//2:
    print("No")
  else:
    print("Yes")
if H%2 == 1 and W%2 == 1:
  if ns4[1]+ns4[3] > 1:
    print("No")
  elif ns4[2]+ns4[3] > H//2+W//2:
    print("No")
  else:
    print("Yes")
