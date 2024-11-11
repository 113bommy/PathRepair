s=input()
ans='NO'
for i in range(1,len(s)):
  for j in range(i,len(s)):
    if s[:i]+s[j:]=='keyence':
      ans='YES'
      break
print(ans)