n=input()
s=list(n)
d=[]
if s[0]=='h':
    d.append(s[0])
    d.append(s[1])
    d.append(s[2])
    d.append(s[3])
    del s[0:4]
else:
    d.append(s[0])
    d.append(s[1])
    d.append(s[2])
    del s[0:3]

d.append('://')
for i in range(len(s)):
    if s[i]=='r' and s[i+1]=='u' and i!=0:
        v=i
        break
    d.append(s[i])
del s[0:v+2]    
d.append('.ru')
if len(s)>0:
    d.append('/')
    for i in range(len(s)):
        d.append(s[i])
for i in range(len(d)) :
    print(d[i],end='')

