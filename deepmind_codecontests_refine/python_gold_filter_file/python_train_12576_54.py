n,*s=open(0)
a=b=c=d=0
for t in s:
    if t[-2]=='A'and t[0]=='B':
        d+=1
    elif t[-2]=='A':
        a+=1
    elif t[0]=='B':
        b+=1
    c+=t.count('AB')
if all(i==0for i in(a,b)):
    print(c+max(0,d-1))
    exit()
elif a==b:
    print(a+c+d)
    exit()
ans=min(a,b)+c
dif=abs(a-b)
ans+=min(dif,d)
d-=min(dif,d)
print(ans+d)