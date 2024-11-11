from operator import itemgetter
def more(a,b):
    if a[0]>b[0]:
        return 0
    if a[0]==b[0]:
        if a[1]> b[1]:
            return 0
    return 1

        
    
t=int(input())
for i in range(t):
    n=int(input())
    s=[]
    res=""
    for j in range(n):
        s.append(list(map(int,input().split())))    
    s.sort()
    
    b=0
    U=0;
    R=0;
    for k in range(n):
        for h in range(n):
            if h==k:
                continue
            else:
                if s[h][0]<s[k][0] and s[h][1]>s[k][1]:
                    print("NO")
                    b=1
                    break
        if b==1:
            break
    if(b==1):
        continue
    
    for j in range(len(s)):
         for j1 in range(s[j][0]-R):
            res+="R"
         R=s[j][0]
         for j1 in range(s[j][1]-U):
             res+="U"
         U=s[j][1]
    print("YES")
    print(res)
                
            
    
        
    
        
    
                
            
    
