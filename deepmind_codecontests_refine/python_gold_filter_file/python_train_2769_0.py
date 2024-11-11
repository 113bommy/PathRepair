a,b=map(int,input().split())
if a>b: a,b=b,a
ans=1
for i in range(2,a+1):
    ans*=i
print(ans)