s = input()
ans = 0
while s:
  if s[0] == s[-1]:
    s = s[1:-1]
  else:
    if s[0] == "x":
      ans += 1
      s = s[1:]
    elif s[-1] == "x":
      ans += 1
      s = s[:-1]
    else:
      print(-1)
      exit()
print(ans)