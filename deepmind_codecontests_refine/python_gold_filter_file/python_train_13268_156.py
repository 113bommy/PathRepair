n=int(input())
ans=0
for i in range(n):
    a,b=map(int,input().split())
    if(a+2<=b):
        ans+=1
print(ans)