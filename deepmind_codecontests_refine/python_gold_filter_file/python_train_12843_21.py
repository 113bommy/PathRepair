n,k=map(int,input().split())
l=list(input().split())
ans=0
for i in l:
    a=i.count('4')
    b=i.count('7')
    if (a+b)<=k:
        ans=ans+1
print(ans)