from collections import Counter

def point(lst):
  counter = Counter(lst)
  acc = 0
  for i in range(2, 10):
    acc += i * counter[i]
  for i in range(10, 14):
    acc += 10 * counter[i]
  one_num = counter[1]
  for i in range(one_num + 1):
    if i + (one_num - i) * 11 + acc <= 21:
      acc += i + (one_num - i) * 11
      break
  else:
    acc += one_num
  if acc > 21:
    return 0
  else:
    return acc

while True:
  s = input()
  if s == "0":
    break
  lst = list(map(int, s.split()))
  print(point(lst))

