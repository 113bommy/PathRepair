t=int(input())
for x in range(t):
    n=int(input())
    s=str(input())
    p='YES'
    # no letter can remain the same 
    for i in range(n//2):
        d=abs(ord(s[i])-ord(s[n-i-1]))
        if d>2 or d==1:
            p='NO'; break 
    print(p)
       

    
    

        
            


