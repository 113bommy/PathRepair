s=input()
n=len(s)
nlower=0
nupper=0
for i in range(n):
  if s[i].lower()==s[i]:
    nlower=nlower+1
  else:
    nupper=nupper+1
if nlower<nupper:
  print(s.upper())
else:
  print(s.lower())
