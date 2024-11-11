

for x in range(int(input())):
    n,q=list(map(int,input().split()))
    a=list(map(int,input().split()))
    t=0
    if n==1:
        print(a[0])
    else:
        v=[]
        if a[0]>a[1]:
            v.append(a[0])
            t=1
            
        for i in range(1,n-1):
            
            if a[i]>a[i-1] and a[i]>a[i+1] and t==0:
                v.append(a[i])
                t=1
            if a[i]<a[i-1] and a[i]<a[i+1] and t==1:
                v.append(a[i])
                t=0
        #print(v)   
        if a[n-1]>a[n-2] and t==0:
            #print(a[n-1],a[n-2])
            
            v.append(a[n-1])
        if len(v)%2==0:
            v.pop()
        ans=0
        #print(v)
        for i in range(len(v)):
            if i%2:
                ans-=v[i]
            else:
                ans+=v[i]
        
            
        print(ans)
    
    