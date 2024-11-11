for _ in range(int(input())):
    s=input() 
    
    i=0 
    n=len(s)
    res=[]
    while i<n:
        if i+5<=n and s[i:i+5]=="twone":
            res.append(i+2+1) 
            i+=5
        elif i+3<=n and (s[i:i+3]=="two" or s[i:i+3]=="one"):
            res.append(i+1+1)  
            i+=3 
        else:
            i+=1
            
    print(len(res))
    print(*res)