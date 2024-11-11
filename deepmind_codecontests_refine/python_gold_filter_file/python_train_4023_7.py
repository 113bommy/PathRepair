n=int(input())
e=set()
nbr=0
e1=set()
e2=set()
for i in range(n):
    c,s=input().split()
    if len(e1|e2)==25:
        e={chr(i+97) for i in range(26)}-(e1|e2)
        
    if len(e)==1:
        if c=='?':
            for x in e:
                break
            if x==s:
                break
            
        if c=='!':
            nbr+=1
        elif c=='?':
            if s not in e:
                nbr+=1
            #e2.add(s)
                #e1.add(s)
        continue

    if c=='!':
        if len(e)!=0:
            e&=set(s)
        else:
            e=set(s)
        
        
    if c==".":
        e1|=set(s)

    if c=='?':
        e2.add(s)
        #if s in e1:
        #    nbr+=1

    e-=e1
    e-=e2
    
        
print(nbr)
