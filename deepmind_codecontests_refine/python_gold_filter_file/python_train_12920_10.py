t=int(input())
for i in range(t):
    s=input()
    a=[x for x in s if 65<=ord(x)<=90]
    b=[x for x in s if 96<=ord(x)<=122]
    c=[x for x in s if 48<=ord(x)<=57]
    l=[len(a),len(b),len(c)]
    j=[x for x in l if x==0]
    k=len(j)
    
    if(k==0):
        print(s)
        continue
    elif(k==2):
        o=ord(s[0])
        if(65<=o<=90):
            s='a9'+s[2:]
        if(96<=o<=122):
            s='A9'+s[2:]
        if(48<=o<=57):
            s='aA'+s[2:]  
    else:
        if(len(a)==0):
            if(len(b)>1):
                e=s.index(b[0])
                s=s[:e]+'A'+s[e+1:]
            else:
                e=s.index(c[0])
                s=s[:e]+'A'+s[e+1:]
        if(len(b)==0):
            if(len(a)>1):
                    e=s.index(a[0])
                    s=s[:e]+'a'+s[e+1:]
            else:
                    e=s.index(c[0])
                    s=s[:e]+'a'+s[e+1:]
        if(len(c)==0):
            
            if(len(a)>1):
                    e=s.index(a[0])
                    s=s[:e]+'1'+s[e+1:]
            else:
                    e=s.index(b[0])
                    s=s[:e]+'1'+s[e+1:]   
                    
    print(s)                    
                
            

    
    