S=input()
s=[]
for i in range(26):
  s=s+[chr(97+i)]
for i in range(len(S)):
  s.remove(S[i])
if len(s)==0:
  for i in range(25):
    if ord(S[24-i])<ord(S[25-i]):
      q=S[25-i:]
      q2=[]
      for j in q:
        if ord(j)<ord(S[24-i]):
          pass
        else:
          q2+=[ord(j)]
      q2.sort()
      
      S=S[:24-i]+chr(q2[0])
      print(S)
      break
    if i==24:
      print(-1)
    
else:
  print(S+s[0])
