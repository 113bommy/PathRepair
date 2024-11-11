input()
color = [0] * 8
gold = 0
for a in map(int, input().split()):
  if a >= 3200:
    gold += 1
  else:
    color[a // 400] = 1
print(max(sum(color), 1), sum(color) + gold)