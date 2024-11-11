n , m = map(int,input().split())
lis=[0]*(3002)
for i in range(n):
    a,b=map(int,input().split())
    lis[a]+=b
#lis.sort()
ans=lef=0
#print(lis[:28])
for i in range(1,3002):
    ans+=lef
    q=max(0,m-lef)
    ans+=min(q,lis[i])
    lef = min(m,lis[i]-min(q,lis[i])) 
#    print(ans,lef,q)  
print(ans)        
