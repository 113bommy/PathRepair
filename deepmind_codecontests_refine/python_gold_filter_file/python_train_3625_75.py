import re
s = input()
matchOB = re.match(r'^A[a-z]+C[a-z]+$', s)
if matchOB:
  print('AC')
else:
  print('WA')