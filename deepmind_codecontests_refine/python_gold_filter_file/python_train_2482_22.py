s = input()
t = input()
s = s[::-1]
t = t[::-1]
for i in range(len(s)-len(t)+1):
  for j in range(len(t)):
    if s[i+j] != t[j] and s[i+j] != '?':
      break
  else:
    break
else:
  print('UNRESTORABLE')
  exit(0)
s = s[:i] + t + s[i+len(t):]
s = s.replace('?','a')
s = s[::-1]
print(s)