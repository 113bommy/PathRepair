import math

tenMinusSix = 0.000001
step = 0.000000000001

def withinMargin(x):
  if x <= tenMinusSix:
    return True
  return False

def verify(a, b):
  if(a < 0 or b < 0):
    return False

  s = a + b
  p = a * b
  dif1 = abs(s - p)
  dif2 = abs(s - d)


  if withinMargin(dif1) and withinMargin(dif2):
    return True

  return False

t = int(input())

for i in range(t):
  sol = []
  d = int(input())
  found = False

  lower = 0
  upper = 2

  while(lower <= upper):
    if verify(lower, d - lower):
      sol = [lower, d - lower]
      found = True
      break

    if(lower == upper):
      break

    if verify(upper, d - upper):
      sol = [upper, d - upper]
      found = True
      break

    middle = (lower + upper) / 2

    if verify(middle, d - middle):
      sol = [middle, d - middle]
      found = True
      break

    if(middle * (d - middle) > d):
      upper = middle - step
    else:
      lower = middle + step

  if(found):
    ans = "Y "
    ans += " ".join('%0.12f' % item for item in reversed(sol))
    print(ans)
  else:
    print('N')