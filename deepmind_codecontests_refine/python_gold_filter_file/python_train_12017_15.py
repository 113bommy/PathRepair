s=input()
t=s.find('=')
a=s[:t]
b=s[t:]
ac=a.count('|')
bc=b.count('|')
if ac==bc:
    ans=s
elif abs(ac-bc)==2:
    if ac>bc:
        if a[-2]=='|':
            ans=a[:len(a)-1]+b+'|'
        else:
            ans=a[1:]+b+'|'
    else:
        ans=a+'|'+b[:len(b)-1]
else:
    ans="Impossible"
print(ans)
        
