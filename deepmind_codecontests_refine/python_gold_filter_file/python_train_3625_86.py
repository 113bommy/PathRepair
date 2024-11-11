import re
S=input()
if S[0]=="A" and S[2:-1].count("C")==1 and len(re.findall("[A-Z]",S))==2:
  print("AC")
else:
  print("WA")
