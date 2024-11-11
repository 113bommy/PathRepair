n=int(input())
s=input()
s=list(s)
c=0
if n==1:
    print(0)
    print(''.join(s))
else:
    for i in range(1,n-1):
        if s[i]==s[i-1]:
            c+=1
            if s[i-1]=='R':
                if s[i+1]=='B':
                    s[i]='G'
                else:
                    s[i]='B'
            elif s[i-1]=='B':
                if s[i+1]=='G':
                    s[i]='R'
                else:
                    s[i]='G'
            else:
                if s[i+1]=='B':
                    s[i]='R'
                else:
                    s[i]='B'
    if s[-1]==s[-2]:
        c+=1
        if s[-2]=='R':
            s[-1]='B'
        elif s[-2]=='B':
            s[-1]='G'
        else:
            s[-1]='R'
    print(c)
    print(''.join(s))
    