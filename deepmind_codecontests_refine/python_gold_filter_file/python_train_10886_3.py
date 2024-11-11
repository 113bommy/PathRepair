input()
s = input()
c = 1
a = ['0', '0']

if len(s) == 1:
  print(1)
else:
  if s[0] == 'L' or s[0] == 'R':
    a[0] = s[0]
  else:
    a[1] = s[0]
  for i in range(1, len(s)):
    if (s[i] == 'R' and a[0] == 'L') or (s[i] == 'L' and a[0] == 'R'):
      c += 1
      a[0] = s[i]
      a[1] = '0'
    elif (s[i] == 'U' and a[1] == 'D') or (s[i] == 'D' and a[1] == 'U'):
      c += 1
      a[1] = s[i]
      a[0] = '0'
    else:
      if a[0] == '0' or a[1] == '0':
        if s[i] == 'L' or s[i] == 'R':
          if a[0] == '0':
            a[0] = s[i]
        else:
          if a[1] == '0':
            a[1] = s[i]

  print(c)