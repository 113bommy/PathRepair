x,y=map(int,input().split())
ans=1
while 2*x<=y:
    x*=2
    ans+=1
print(ans)