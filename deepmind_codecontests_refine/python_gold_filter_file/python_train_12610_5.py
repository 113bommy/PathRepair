n=int(input())
s=input()
s=list(s)
z,o,t=0,0,0
for i in range(0,n):
    if s[i]=='1':o+=1
    elif s[i]=='0':z+=1
    elif s[i]=='2':t+=1
for i in range(0,n):
    if s[i]=='1' and o>n//3 and z<n//3:
        s[i]='0'
        z+=1
        o-=1
    elif s[i]=='2':
        if t>n//3 and z<n//3:
            s[i]='0'
            z+=1
            t-=1
        elif t>n//3 and o<n//3:
            s[i]='1'
            t-=1
            o+=1
for i in range(1,n+1):
    if s[-i]=='0':
        if z>n//3 and t<n//3:
            s[-i]='2'
            t+=1
            z-=1
        elif z>n//3 and o<n//3:
            s[-i]='1'
            o+=1
            z-=1
    elif s[-i]=='1' and o>n//3 and t<n//3:
        s[-i]='2'
        o-=1
        t+=1
a="".join(str(a) for a in s)
print(a)