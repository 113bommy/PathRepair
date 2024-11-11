x=list(input())
y=list(input())+['']
for a, b in zip(x, y):
  print(a+b, end='')