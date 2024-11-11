t=int(input())
for i in range(0,t,1):
    x,y=map(int,input().split())
    a,b=map(int,input().split())
    ans=min((x+y)*a,min(x,y)*b+(max(x,y)-min(x,y))*a)
    print(ans)
