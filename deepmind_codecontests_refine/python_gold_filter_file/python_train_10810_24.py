s = input()[:-1]
while s[0:len(s)//2] != s[len(s)//2:]:
  s = s[:-1]
print(len(s))