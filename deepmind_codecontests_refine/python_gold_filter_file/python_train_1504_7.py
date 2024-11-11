n=int(input())
p=-1000000001
l=1000000001
for x in range(n) :
    s=input().split()
    r=int(s[1])
    if s[2]=="Y" :
        if s[0]==">=" :
            p=max(p,r)
        if s[0]==">" :
            p=max(p,r+1)
        if s[0]=="<=" :
            l=min(l,r)
        if s[0]=="<" :
            l=min(l,r-1)
    else :
        if s[0]=="<" :
            p=max(p,r)
        if s[0]=="<=" :
            p=max(p,r+1)
        if s[0]==">" :
            l=min(l,r)
        if s[0]==">=" :
            l=min(l,r-1)
if p<=l :
    print(p)
else :
    print("Impossible")
        
        
            
        
