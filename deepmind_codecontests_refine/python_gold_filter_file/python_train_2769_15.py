a,b=map(int,input().split())
x=min(a,b)
ans=1
#print(x)
for i in range(1,x+1):
    ans=ans*i
print(ans)