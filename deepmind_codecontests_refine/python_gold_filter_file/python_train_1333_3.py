a = [int(input()) for i in range(5)]
m = 0
n = 0
for i in a:
  if i%10 != 0:
    t = 10 - i%10
  else:
    t = 0
  n += i + t
  m = max(m,t)
print(n-m)