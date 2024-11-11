t=int(input())

while t>0:
    t-=1
    
    n = int(input())
    
    l1=[int(i) for i in input().split(" ")]
    
    l2=[int(i) for i in input().split(" ")]
    
    k = min(l1)
    z = min(l2)
    ans=0
    
    for i in range(n):
        temp1 = abs(k-l1[i])
        temp2 = abs(z-l2[i])
        
        ans+=max(temp1,temp2)
        
    print(ans)