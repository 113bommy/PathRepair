for _ in range(int(input())):
    p=input()
    h=input()
    
    d={}
    f=0
    for i in h:
        d[i]=-1
    for i in p:
        if i not in d:
            print("NO")
            f=1
            break
        if d[i]==-1:
            d[i]=0
        d[i]+=1
    
    if f==1:
        continue
    
    psize=len(p)
    
    for i in range(len(h)):
        if d[h[i]]>0:
            match=i
            temp=d.copy()
            c=0
            for j in range(match,len(h)):
                if temp[h[j]]<1:
                    break
                c+=1
                temp[h[j]]-=1
                if c==psize:
                    break
            if c==psize:
                print("YES")
                f=1
                break
    if f==0:
        print("NO")
        
            