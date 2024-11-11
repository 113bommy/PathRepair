line = input()
res = []
for e in line:
  if len(res) > 0:
    if res[-1] == '/':
      if e == '/':
        continue
      else:
        res.append(e)
    else:
      res.append(e)
  else:
    res.append(e)
if len(res) == 1:
  print(''.join(res))
else:
  i = len(res) - 1
  while res[i] == '/' and i > 0:
    i -= 1
  print(''.join(res[:(i + 1)]))
  