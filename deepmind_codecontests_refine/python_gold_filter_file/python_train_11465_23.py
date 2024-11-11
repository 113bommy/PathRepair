t = int(input())
while t > 0:
  t -= 1
  d = float(input())
  if d == 0:
    print("Y 0.000000 0.000000")
    continue
  lo,hi = 1.0,2.0
  for i in range(0,205):
    md = (lo + hi) / 2.0
    if (d-md) >= (d / md):
      hi=md
    else:
      lo=md
  
  if abs((d-lo) -  (d / lo)) > 0.000001:
    print('N')
  else:
    print("Y {:.10f}".format(d-lo) +  " {:.10f}".format(lo))