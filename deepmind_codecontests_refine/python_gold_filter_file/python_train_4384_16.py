w, h, k = [int(x) for x in input().split(' ')]
cnt = 0
cw = w
ch = h
for i in range(k):
  cnt += 2*(cw+ch)-4
  cw -= 4
  ch -= 4
print(cnt)
