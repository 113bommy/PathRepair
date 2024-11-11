n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()

c=list(set(a))

b=[[] for i in range(200005)]

for i in a:
    temp=i;j=0
    b[temp].append(0)

    if temp!=1:
        while(1):
            temp=temp//2
            j+=1
            b[temp].append(j)
            if temp==1:
                break

res=2000000005     
for i in range(1,max(a)+1):
    if len(b[i])>=m:
        temp=sum(b[i][:m])
        res=min(res,temp)
print(res)
    
