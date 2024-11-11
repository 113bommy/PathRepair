n=int(input())
a=[int(x) for x in input().split()]
b=[0]*(10**6+1)
tmp=0
res=[]
tmp2=[]
d=True
for i in range(n):
    if a[i]>0:
        if b[a[i]]==0:
            b[a[i]]+=1
            tmp+=1
            tmp2.append(a[i])
        else:
            d=False
            break
    else:
        if b[-a[i]]==1:
            tmp-=1
            b[-a[i]]+=1
            if tmp==0:
                for j in tmp2:
                    b[j]=0
                tmp2=[]
                res.append(i+1)
        else:
            d=False
            break
if d and tmp==0:
    for i in range(len(res)-1,0,-1):
        res[i]-=res[i-1]
    print(len(res))
    print(*res)
else:
    print(-1)
