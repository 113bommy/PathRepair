input()
s = input() + 's '
f = s.find('ogo')
while f != -1:
  c = f+3
  while s[c] + s[c+1] == 'go':
    c += 2
  s = s[:f] + '***' + s[c:]
  f = s.find('ogo')
print(s[:len(s)-2])