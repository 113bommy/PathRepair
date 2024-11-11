x,y=map(int,input().split())
n=int(input())
m=1000000000+7
dp=[x,y,y-x,-x,-y,x-y]
print(dp[(n-1)%6]%m)
    
