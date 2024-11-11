n = int(input())
s = input()

count = 0
for i in range(1000):
  pin = "00" + str(i)
  pin = pin[-3:]
  
  idx = 0
  for j in range(n):
    if s[j] == pin[idx]:
      idx += 1
      
    if idx == 3:
      break

  if idx == 3:
    count += 1
      
print(count)