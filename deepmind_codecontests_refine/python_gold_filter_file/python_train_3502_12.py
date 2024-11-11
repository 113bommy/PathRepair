n=list(map(int,input().split()))
l=[]
p=[]
for i in range(n[0]):
    m=list(map(str,input().split()))
    m[1]=m[1]+';'
    l.append(m)
for o in range(n[1]):    
    b=list(map(str,input().split()))
    p.append(b) 
for u in range(n[1]):
    for e in range(n[0]):
    
         if l[e][1]==p[u][1]: 
            
            print(p[u][0],end=' ')
            print(p[u][1],end='')     
            print(' #',end='')     
            print(l[e][0])
            

            
        