import re
s = input()
t = input()
 
s = s.replace("?", ".")[::-1]
t = t[::-1]
 
for i in range(len(s) - len(t) + 1):
  if re.match(s[i:i+len(t)], t):
    s = s[:i].replace(".","a") + t + s[i+len(t):].replace(".","a")
    print(s[::-1])
    break
else:
  print("UNRESTORABLE")