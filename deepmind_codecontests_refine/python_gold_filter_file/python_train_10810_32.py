s = input()
while True:
  s = s[:len(s) - 2]
  if s[:len(s) // 2] == s[len(s) // 2:]:
    break
print(len(s))
