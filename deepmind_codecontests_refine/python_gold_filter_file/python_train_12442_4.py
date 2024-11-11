user_input = input().split(' ')

n = int(user_input[0])
m = int(user_input[1])

res = 0

for i in range(0, n):
  row = input().split(' ')
  index = 1000000001
  for a in row:
    index = min(index, int(a))
  res = max(res, index)

print(res)