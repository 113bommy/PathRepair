v1,v2=map(int,input().split())
t,d=map(int,input().split())

ans=0
for i in range(1,t+1):
    ans+=min(v1+d*(i-1),v2+d*(t-i))

print(ans)