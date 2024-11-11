import re
s = input()
t = s[2:-1]
if(s[0] == "A" and len(re.findall('[a-z]', s))==len(s)-2 and "C" in t):
  print("AC")
else:
  print("WA")