t=int(input())
for i in range(t):
    n,m=[int(n) for n in input().split()]
    arr=[int(item) for item in input().split()]
    brr=[int(item) for item in input().split()]
    d=dict()
    for i in range(1001):
        d[i]=0
    for j in arr:
        d[j]=d[j]+1
    flag=0
    for k in brr:
        if(d[k]>0):
            s=k
            flag=1
            break
    if(flag==1):
        print("YES")
        print(1,s)
    else:
        print("NO")
        
        
        
        
   
        
  

       
            



