h, w = map(int, input().split())
d = {}
for i in range(h):
  for c in input():
    if c in d:
      d[c] += 1
    else:
      d[c] = 1
m = ((w + 1)// 2) * ((h + 1) // 2)
ans = "Yes"
if len(d.keys()) > m:
  ans = "No"
oc = 0
fc = 0
for key in d:
  oc += d[key] % 2
  fc += d[key] // 4
if oc > 1 or fc < (w//2) * (h//2):
  ans = "No"
print(ans)
