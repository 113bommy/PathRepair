n = int(input())
s = input()

count = 0
for i in range(1000):
  tmp = format(i, '03')
  k = 0
  for j in s:
    if j == tmp[k]:
      k+=1
    if k == 3:
      count+=1
      break
print(count)
    