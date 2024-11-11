n,k=map(int,input().split())
id=list(map(int,input().split()))
d={}
for i in id:
    d[i]=0
lis=[0]*k
l=0
str=0
end=0
for i in id:
    if d[i]!=1:
        if l == k:
            t = lis[str]
            lis[str]=i
            str=(str+1)%k
            end=str-1
            if str==0:
                end=n-1
            d[i]=1
            d[t]=0
        else:
            end+=1
            lis[l]=i
            d[i]=1
            l+=1

print(l)
if str==0:
    for i in range(l-1,-1,-1):
        print(lis[i],end=" ")
else:

    for i in range(end,-1,-1):
        print(lis[i], end=" ")
    for i in range(l-1,str-1,-1):
        print(lis[i],end=" ")

