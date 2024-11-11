s=input()
l=s.replace('BC','D')
a=0
ans=0
for i in range(len(l)):
  if l[i]=='A':
    a+=1
  elif l[i]=='D':
    ans+=a
  else:
    a=0
print(ans)
