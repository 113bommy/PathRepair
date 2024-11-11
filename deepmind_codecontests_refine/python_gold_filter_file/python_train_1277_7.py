import math
t=int(input())
while t:
    t-=1
    n=int(input())
    a=sorted(list(map(int,input().split())),reverse=True)
    b=[]
    b.append(a[0])
    a.remove(a[0])
    
    for j in range(1,n):
        i=0
        tem=1
        if j==1:
            mx=b[0]

        while i <len(a):
            
            k=math.gcd(mx,a[i])
            if k >=tem:
                tem=k
                relee=a[i]
            i+=1
        mx=math.gcd(mx,relee)
        a.remove(relee)
        #print(a,mx)
        b.append(relee)
    print(*b)
        
                
                
            
            
    