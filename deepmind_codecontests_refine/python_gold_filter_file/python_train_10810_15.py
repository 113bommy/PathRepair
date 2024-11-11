s = input()[:-2]
ls = len(s) // 2
while s[:ls] != s[ls:]:
  ls -= 1
  s = s[:-2]
print(ls*2)
