n = int(input())
a = list()
for i in range(n):
  r = input()
  s = input()
  a.append(s)  
def f(x):
  if '1' in x:
    for i in range(len(x)):
      if x[i] == '1':
        max = i+1
    max1 = 2*max
    for i in range(1, len(x)+1):
      if x[-i] == '1':
        max = i
    max2 = 2*abs(max)
    if max1 > max2:
      return max1
    return max2
  return len(x)
for i in range(n):
  print(f(a[i]))