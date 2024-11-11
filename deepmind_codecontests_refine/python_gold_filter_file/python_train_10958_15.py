
t=int(input())
for _ in range(t):
    x1,y1,z1=map(int,input().split())
    x2,y2,z2=map(int, input().split())
    ans=min(z1,y2)
    y2-=ans;z1-=ans
    ans*=2
    if z2<=x1+z1:
        print(ans)
    else:
        print(ans-(z2-x1-z1)*2)
    
