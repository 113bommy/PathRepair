n = int(input())
s = input().strip()
assert n == len(s)

maxlen = 0
for offset in range(1, n):
  t = s[offset:]
  d = 0
  for (a, b) in zip(s, t):
    if a == b:
      d += 1
    else:
      d = 0
    if maxlen < d and d <= offset:  # (d > offset) のとき共通部分文字列が重なってる
      maxlen = d

print(maxlen)