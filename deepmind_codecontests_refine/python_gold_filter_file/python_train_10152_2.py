
l,r,k=map(int,input().split())
l1=[]
k1=1
while k1<=r :
    if k1>=l :
        l1.append(k1)
    k1=k1*k
if len(l1)==0 :
    print(-1)
else :
    print(*l1)
    
