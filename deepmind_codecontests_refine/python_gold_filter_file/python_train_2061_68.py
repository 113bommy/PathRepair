s = input()

odd = s[0::2]
even = s[1::2]

if 'L' in odd or 'R' in even:
  print('No')
else:
  print('Yes')