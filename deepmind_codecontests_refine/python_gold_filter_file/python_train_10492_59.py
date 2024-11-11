import re

S = input() 

if re.match(r'^(hi)+$',S):
  print('Yes')

else:
  print('No')