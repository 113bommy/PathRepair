x = int(input())
i = 0
p = 100
while p < x:
  p += p//100
  i +=1
print(i)