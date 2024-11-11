def nine(p) :
    
    s=''
    for i in range(p) :
        s+='9'
    return int(s)
def prosh(p) :
    ans=0
    for i in range(1,p+1) :
        ans+=nine(i)*9
    return ans
        
n,k=map(int,input().split())
l=[0]*29
for i in range(19) :
    
    e=nine(19-i)
    
    l[i]=k//e
    
    k-=l[i]*e
    
    if k==0 :
        
        break
    if i==18  or k%e>prosh(19-i-1) :
        
        l[i]+=1
        break
otv=0
for i in range(19) :
    
    otv+=10**(19-i)*l[i]

print(max(n-otv+1,0))
    
    
    
        
