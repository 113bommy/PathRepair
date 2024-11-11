s=input()
ans=""
if s[0]=='f':
    ans+='ftp://'+s[3]
    t=-1
    for i in range(4,len(s)-1):
        if s[i]=='r' and s[i+1]=='u':
            t=i
            break
    ans+=s[4:t]+".ru"
    if len(s[t+2:])>0:
        ans+="/"+s[t+2:]
    print(ans)
        
else:
    ans+='http://'+s[4]
    t=-1
    for i in range(5,len(s)-1):
        if s[i]=='r' and s[i+1]=='u':
            t=i
            break
    ans+=s[5:t]+".ru"
    if len(s[t+2:])>0:
        ans+="/"+s[t+2:]
    print(ans)
        
    
