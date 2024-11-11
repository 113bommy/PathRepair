import re
 
S = input()
matchObj = re.match("^A[a-z]+C{1}[a-z]*[a-z]$", S)
if matchObj:
  print("AC")
else:
  print("WA")