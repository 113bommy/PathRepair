n,x=map(int,input().split())
res=0
for i in range(1,n+1):
    if x%i==0:
        tmp=x//i
        if tmp<=n:
            res+=1
print(res)
    