t=int(input())
ans=[]
for kk in range(t):
    n,p,k=list(map(int,input().split()))
    goods=list(map(int,input().split()))
    goods.sort()
    l=0
    h=n-1
    m=(l+h)//2
    while l<=h:
        t=sum(goods[m::-2])
        if p-t<0:
            h=m-1
            m=(l+h)//2
        else:
            l=m+1
            m=(l+h)//2
            
            
    print(m+1)    
