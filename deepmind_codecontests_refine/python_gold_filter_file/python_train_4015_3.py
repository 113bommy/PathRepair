
n=int(input())
l=input()
i=0
a=[]
c=0
b=0
k=0
while i<n:
    if 'B' not in l:
        print(0)
        k=1
        break
    if l[i]=='W':
        if b!=0:
            a.append(str(b))
            c+=1
            b=0
    else:
        b+=1
    i+=1
if b!=0:
    c+=1
    a.append(str(b))
if k!=1:    
    print(c)
    print(" ".join(a))
        

        
        
    
    
    

        
    

