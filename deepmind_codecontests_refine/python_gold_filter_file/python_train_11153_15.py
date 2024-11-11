n=int(input())
s=list(input())
st=""
for i in range(n):
    st+=s[i]
for i in range(1,n):
    if s[i]==s[i-1] and i!=n-1:
        if s[i]=='R':
            if s[i+1]!='B':
                s[i]='B'
            else:
                s[i]='G'
        elif s[i]=='G':
            if s[i+1]!='R':
                s[i]='R'
            else:
                s[i]='B'
        elif s[i]=='B':
            if s[i+1]!='G':
                s[i]='G'
            else:
                s[i]='R'
        continue
    if s[i]==s[i-1] and i==n-1:
        if s[i-1]=='R':
            s[i]='G'
        else:
            s[i]='R'
c=0
for i in range(n):
    if s[i]!=st[i]:
        c+=1
print(c)
print("".join(s))