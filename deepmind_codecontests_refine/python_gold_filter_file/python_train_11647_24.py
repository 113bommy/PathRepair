s = input()
p2 = s[0]
p1 = s[1]
ans = "-1 -1"
if p2 == p1 :
  ans = '1 2'
else:
  for i in range(2,len(s)):
    if p2 == s[i] or p1 == s[i]:
      ans = str(i-1)+" "+str(i+1)
      break
    p2 = s[i-1]
    p1 = s[i]
print(ans)
