from itertools import product

H, W, K = map(int, input().split())
grid = ""

for _ in range(H):
  grid += input()

ans = 10000

for Hcut in product((0, 1), repeat = H-1):
  Gr_num = sum(Hcut) + 1
  old = [0]*Gr_num
  cnt = 0
  for i in range(W):
    #縦一列のchocoを見る
    choco = grid[i::W]
    new = [0]*Gr_num
    gr = 0
    for j in range(H):
      new[gr] += int(choco[j])
      if j < H-1:
        if Hcut[j] == 1:
          gr += 1
    #そもそも一列でオーバーしてたら詰み。
    if max(new) > K:
      cnt += 10000
      break
    #新しい一列を追加しても大丈夫か確認
    check = [old[gr] + new[gr] for gr in range(Gr_num)]
    if max(check) > K:
      old = new[:]
      cnt += 1
    else:
      old = check[:]
  ans = min(ans, cnt+sum(Hcut))

print(ans)