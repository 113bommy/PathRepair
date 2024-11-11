s=input()
t=input()
n=len(s)
c=0
l=[]
for i in range(n):
    if(s[i]==t[i]):
        l.append(s[i])
    else:
        if(c%2==1):
            l.append(s[i])
        else:
            l.append(t[i])
        c=c+1

if(c%2==1):
    print("impossible")
else:
    print(''.join(l))
