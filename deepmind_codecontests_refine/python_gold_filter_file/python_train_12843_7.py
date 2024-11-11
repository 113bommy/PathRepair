n,k=map(int,input().split())
l=list(map(int,input().split()))
ans=0
for i in l:
    c=0
    while(i>0):
        t=i%10
        if(t==4 or t==7):
            c+=1
        i=i//10
    if(c<=k):
        ans+=1
print(ans)
