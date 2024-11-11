t=int(input())
for _ in range(t):
    a,s=input().split()
    b=''
    a=list(map(int,a))
    s=list(map(int,s))
    iS=len(s)-1
    key=True
    for i in range(len(a)-1,-1,-1):
        if s[iS]==a[i]:
            b+='0'
            iS-=1
        elif s[iS]>a[i]:
            b+=str(s[iS]-a[i])
            iS-=1
        else:
            if iS>0:
                if s[iS-1]==1:
                    b+=str(10+s[iS]-a[i])
                    iS-=2
                else:
                    key=False
                    break
            else:
                key=False
                break
        if i>0 and iS<0:
            key=False
            break
    if key==False:
        print('-1')
    else:
        for i in range(iS,-1,-1):
            b+=str(s[i])
        print(int(b[::-1]))
        
        
            
        
                
            
        
        
    
    
        
    
