n=int(input())
ls=[ list(input().split()) for i in range(n) ]
ma,m,f=0,0,0
for i in range(367):
    m,f=0,0
    for j in range(n):
        if int(ls[j][1]) <= i and int(ls[j][2]) >= i :
            if ls[j][0]=='M':
                m+=1
            else :
                f+=1
    
    ma=max(ma,min(m,f)*2)
print(ma)    
        
    