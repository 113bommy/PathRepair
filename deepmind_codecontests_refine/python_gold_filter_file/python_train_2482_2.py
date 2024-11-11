import re
s=str(input())
s = s.replace('?', '.')
t=str(input())
for i in range(len(s)-len(t),-1,-1):
  if re.match(s[i:i+len(t)],t):
    s=s.replace(".","a")
    print(s[:i]+t+s[i+len(t):])
    exit()
else:
  print("UNRESTORABLE")