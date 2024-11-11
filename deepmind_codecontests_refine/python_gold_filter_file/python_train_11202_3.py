a=input().upper()
b=input().upper()
c=input()
d=c
#print(a,b,c,d)
ans=""
for i,h in zip(list(c.upper()),list(d)):
    if i in a:
        ans+=chr(ord(h)-(ord(a[a.index(i)])-ord(b[a.index(i)])))
    else:
        ans+=h
print(ans)