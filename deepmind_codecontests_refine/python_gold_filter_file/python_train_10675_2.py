import sys
s = input()
if '.' not in s:
    s += ".0"
if s[0]=='.':
    s='0'+s
if s[-1]=='.':
    s=s+'0'
i=0
while s[i]=='0':i+=1
if s[i]=='.':i-=1
s=s[i:]
i=len(s)-1
while s[i]=='0':i-=1
if s[i]=='.':i+=1
s=s[:i+1]

i=s.index('.')
if i==1 and s[0]=='0':
    e=1
    i=2
    while s[i]=='0':
        i+=1
        e+=1
    res=s[i]+'.'+s[i+1:]
    if res[-1]=='.':res=res[:-1]
    res+='E'+str(-e)
    print(res)
    sys.exit(0)

if i==1:
    i=len(s)-1
    while s[i] == '0': i -= 1
    s = s[:i + 1]
    if s[-1] == '.': s = s[:-1]
    print(s)
    sys.exit(0)

e=i-1
s=s.replace('.','')
s=s[0]+'.'+s[1:]
i=len(s)-1
while s[i]=='0':i-=1
s=s[:i+1]
if s[-1]=='.':s=s[:-1]

res=s+'E'+str(e)
print(res)