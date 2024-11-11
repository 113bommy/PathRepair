s=input()
t=input()
ls=len(s)
lt=len(t)
f=False
for i in range(ls-lt,-1,-1):
  f=True
  for j in range(lt):
    if not(s[i+j]=="?" or s[i+j]==t[j]):
      f=False
      break
  if f:
    ns=s[:i]+t+s[i+lt:]
    print("".join(map(lambda x:"a" if x=="?" else x,list(ns))))
    break
if not f:
  print("UNRESTORABLE")