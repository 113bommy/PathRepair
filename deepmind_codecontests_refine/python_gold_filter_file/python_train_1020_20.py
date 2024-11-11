n = input()

def abc(s):
  t = all(('3' in s, '5' in s, '7' in s))
  if len(s) < len(n):
    return abc(s+'3') + abc(s+'5') + abc(s+'7') + t
  elif s <= n:
    return t
  else:
    return 0

print(abc(''))