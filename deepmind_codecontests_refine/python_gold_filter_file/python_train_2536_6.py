s=input()
t=[]
k=''
for i in range(len(s)-1):
  if s[i]=='r' and s[i+1]=='u':
    t.append(i)
if 'http' in s[0:5]:
    k+=('http://')
    if len(t)>2:
        k+=(s[4:t[1]])
        k+=('.')
        k+=('ru/')
        k+=(s[t[1]+2:len(s)])
    else:
      k+=(s[4:t[0]])
      k+=('.')
      if t[0]==len(s)-2:
        k+=('ru')
      else:
        k+=('ru/')
      k+=(s[t[0]+2:len(s)])
 
if 'ftp' in s[0:3]:
    k+=('ftp://')
    if len(t)>2:
        k+=(s[3:t[1]])
        k+=('.')
        k+=('ru/')
        k+=(s[t[1]+2:len(s)])
    else:
      k+=(s[3:t[0]])
      k+=('.')
      if t[0]==len(s)-2:
        k+=('ru')
      else:
        k+=('ru/')
      k+=(s[t[0]+2:len(s)])
print(k)