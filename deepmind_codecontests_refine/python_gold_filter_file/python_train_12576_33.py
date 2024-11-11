n=int(input())
s=[str(input()) for i in range(n)]
#print(s)
ans=0
x=0
y=0
z=0
for i in range(n):
    ans+=s[i].count('AB')
    if s[i][0]=='B' and s[i][-1]=='A':
        x+=1
        y+=1
        z+=1
    elif s[i][-1]=='A':
        x+=1
        z+=1
    elif s[i][0]=='B':
        y+=1
        z+=1
p=(x-1 if x==y==z>0 else min(x,y))
print(ans+p)