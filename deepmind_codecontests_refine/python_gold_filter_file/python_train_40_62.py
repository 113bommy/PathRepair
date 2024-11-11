
x,y=list(map(int,input().split()))
c=0
ans=0
while(x>0):
    ans+=x
    c+=x
    x=0
    x+=c//y
    c%=y
print(ans)
