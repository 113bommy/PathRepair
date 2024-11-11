p = input()
a = p.index(" ")
b = a
a = int(p[:a])
p = p[b + 1:]
b=int(p)
r=a*2
g=a*5
bl=8*a
ans=0
if(r%b==0):
    ans+=r/b
else:
    ans+=(r//b)+1
if(g%b==0):
    ans+=g/b
else:
    ans+=(g//b)+1
if(bl%b==0):
    ans+=bl/b
else:
    ans+=(bl//b)+1
ans=int(ans)
print(ans)