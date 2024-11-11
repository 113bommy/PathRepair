n = int(input())
x = input()
x10 = int(x, 2)
lenx = len(x)

maxbit = x.count("1")
xc0 = x10 % (maxbit + 1)
xc1 = x10 % (maxbit - 1) if maxbit > 1 else 0

def f(ii):
  cnt = 0
  while ii > 0:
    ii %= bin(ii).count("1")
    cnt += 1
  return cnt

for i in range(lenx):
  if x[i] == "0":
    t = xc0 + pow(2, (lenx - 1 - i), maxbit + 1)
    ans = f(t % (maxbit + 1)) + 1
  else:
    if maxbit - 1 == 0:
      ans = 0
    else:
      t = xc1 - pow(2, (lenx - 1 - i), maxbit - 1)
      ans = f(t % (maxbit - 1)) + 1
  print(ans)
  
  
