n,k=map(int,input().split())

a=list(map(int,input().split()))
ans=[]
for i in range(n):
    s=0
    for j in range(i,n):
        s+=a[j]
        if (j-i+1>=k):
            ans.append(s/(j-i+1))
print(max(ans))
            
            
            
        
        