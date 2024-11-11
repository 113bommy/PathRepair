s1=input()
s2=input()
h1=int(s1[:2])
m1=int(s1[3:])
h2=int(s2[:2])
m2=int(s2[3:])
r=((h2-h1)*60+m2-m1)//2
h1+=(m1+r)//60
m1=(m1+r)%60
h1=str(h1)
m1=str(m1)
if len(h1)==2:
    pass
else:
    h1='0'+h1
if len(m1)==2:
    pass
else:
    m1='0'+m1
ans=h1+':'+m1
print(ans)