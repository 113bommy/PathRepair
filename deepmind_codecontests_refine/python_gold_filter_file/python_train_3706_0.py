n,m=map(int,input().split())
i=n+1
for i in range(i,m+1):
    t=0
    for j in range(2,i):
        if(i%j==0):
            t=1
            break

    if((i==m and t==1 )or t==0 and i!=m):
        print("NO")
        break
    elif(i==m and t==0):
        print("YES")
        break
    else:
        continue
    
        
        
