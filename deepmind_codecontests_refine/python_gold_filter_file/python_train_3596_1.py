#A. Free Ice Cream
row, stock = [int (x) for x in input().split()]
kid = 0

for y in range(row):
  queue = input().split()
  num = int(queue[1])
  if queue[0] == '+':
    stock += num
  else:
    if stock >= num:
      stock -= num
    else:
      kid += 1
print (stock, kid)
