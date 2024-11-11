n, x ,y = map(int, input().split(' '))
a = list(map(int, input().split(' ')))


one_shot = 0
for i in a:
  if i <= x:
    one_shot += 1

if (x <= y):
  print((one_shot+1)//2)
else:
  print (n)

