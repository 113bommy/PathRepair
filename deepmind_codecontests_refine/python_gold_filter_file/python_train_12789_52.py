a=""
s,t=input(),input()
for i in range(len(s)):
  a+=s[i]
  if i<len(t):a+=t[i]
print(a)