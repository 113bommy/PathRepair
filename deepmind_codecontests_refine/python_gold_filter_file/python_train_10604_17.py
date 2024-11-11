s = input()
t = "CODEFESTIVAL2016"
c = 0
for i in range(16):
  if s[i] != t[i]:
    c += 1
print(c)