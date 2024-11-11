t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    s=list(input())
    inc=[0 for i in range(n+1)]
    flag=1
    for i in range(n):
        if(a[i]<=0 and s[i]=='B' ):
            flag=0
            break
        if(a[i]>n and s[i]=='R' ):
            flag=0
            break
        
    for i in range(n):
        if(s[i]=='R' and a[i]>=1 and a[i]<=n):
            inc[a[i]]+=1
    #print(inc)
    c=0
    j=1
    for i in range(n,0,-1):
        c+=inc[i]
        if(c>j):
            #print(c,i)
            flag=0
        
            break
        j+=1
    dec=[0 for i in range(n+1)]
    for i in range(n):
        if(s[i]=='B' and a[i]>=1 and a[i]<=n):
            dec[a[i]]+=1
    c=0
    for i in range(1,n+1):
        c+=dec[i]
        if(c>i):
            flag=0
            break
    if(flag==0):
        print("NO")
        continue
    print("YES")
    
        
            
        
    
        
        
