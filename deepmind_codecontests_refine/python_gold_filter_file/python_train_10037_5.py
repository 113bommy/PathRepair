s = input()
ans = ""
i = 0
first = True
while i < len(s):
  c = s[i]
  d = 1
  while i+d < len(s) and s[i+d] == c:
      d+=1
  if d > 1:
      if first:
        ans += 2*c
        first = False
      else :
        ans += c  
        first = True
  else:
      ans += c
      first = True
  i += d  
print(ans)