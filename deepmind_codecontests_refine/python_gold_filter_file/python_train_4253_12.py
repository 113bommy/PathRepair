s=input()
l=0
r=len(s)-1
x=0
while l<r:
  if s[l]==s[r]:
    l+=1
    r-=1
  elif s[l]=='x':
    x+=1
    l+=1
  elif s[r]=='x':
    x+=1
    r-=1
  else:
    x=-1
    break
print(x)