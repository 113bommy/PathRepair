x = list(input())
c = 0
for i in x:
  if i == "S":
    c += 1
  elif c>0:
    c -= 1
print(2*c)
  
