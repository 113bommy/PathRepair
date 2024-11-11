n = int(input())
sum_b = 0
answer = []
for i in range(n):
  a = int(input())
  b = a // 2
  if a % 2 == 0:
      None
  else:
    if sum_b == 1:
      b -= 1
      sum_b -= 1
    elif sum_b == -1:
      b += 1
      sum_b += 1
    else:
      sum_b -= 1
  answer.append(b)
for i in answer:
  print(i)