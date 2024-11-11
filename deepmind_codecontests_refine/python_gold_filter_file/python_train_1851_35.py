N,D=map(int,input().split())
ans=0

for i in  range(N):
    x,y=map(int,input().split())
    if(D*D>=x*x+y*y):ans+=1
     
print(ans)