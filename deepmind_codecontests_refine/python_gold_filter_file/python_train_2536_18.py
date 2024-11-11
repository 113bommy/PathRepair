try:
    s=input()
    l=[]
    c=0
    x=0
    for i in range(len(s)):
        if s[i]=='p' and i<=3:
            l.append(s[i])
            l.append('://')
            
            
        elif s[i]=='r' and i<(len(s)-1) and s[i+1]=='u' and c==0 and l[-1]!='://':
            if c==0:
                l.append('.ru')
                x=1
                
                c=i+1
            if i+1<len(s)-1:
                l.append('/')
                
        elif s[i]=='u' and i==c:
            pass
        else:
            l.append(s[i])
            
            
    ans="".join(l)
    print(ans)
        
        
        
            
        
            
    


except EOFError:
    pass