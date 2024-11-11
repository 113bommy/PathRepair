k = int(input())
num = map(int, input())
count = [0 for _ in range(10)]

from math import ceil

s = 0

for n in num:
  s += n
  count[n] += 1

diff = k - s

digits = 0

for i in range(9):
  if diff < 0:
    break
  if diff < count[i] * (9-i):
    digits += ceil(diff/(9-i))
    diff -= (9-i) * ceil(diff/(9-i))
  else:
    digits += count[i]
    diff -= count[i] * (9-i)
print(digits)

