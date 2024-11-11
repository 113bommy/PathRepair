s=input()
st=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
f=True
use=set()
last=-1
for i in range(len(s)):
    if s[i] in use:
        pass
    elif s[i] !=st[last+1]:
        f=False
        break
    else:
        use.add(s[i])
        last+=1
    
    
            
        
if f:   
    print("YES")
else:
    print("NO")