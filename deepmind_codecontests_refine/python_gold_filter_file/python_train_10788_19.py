left = 0
right = 0
for i in range(int(input())):
  x, y = map(int, input().split())
  if x < 0: left += 1
  else: right += 1
print('Yes' if right <= 1 or left <= 1 else 'No')
