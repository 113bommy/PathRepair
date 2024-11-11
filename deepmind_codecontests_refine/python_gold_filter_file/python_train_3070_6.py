s=input()
t=input()
c=0
n=len(s)
for j in range(n):
    if s[j]!=t[j]:
        c+=1
if c%2!=0:
    print('impossible')
else:
    c1=0
    c2=0
    p=""
    for j in range(n):
        if s[j]==t[j]:
            p+=s[j]
        else:
            if c1<c//2:
                c1+=1
                p+=s[j]
            else:
                p+=t[j]
    print(p)