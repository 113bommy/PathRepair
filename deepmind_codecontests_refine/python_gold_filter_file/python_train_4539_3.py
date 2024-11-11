s=list(' '+input())
m=0
for i in range(len(s)):
    ss=[]
    for i0 in range(len(s)):
        ss.append(s[i0])
    if ss[i]=='V':
        ss[i]='K'
    elif ss[i]=='K':
        ss[i]='V'
    mm=0
    for i0 in range(len(s)-1):
        if ss[i0]=='V'and ss[i0+1]=='K':
            mm=mm+1
    if mm>m:
        m=mm
print(m)
