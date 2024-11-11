A,B,M=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=200006
for i in range(M):
    x,y,c=map(int,input().split())
    ans=min(ans,a[x-1]+b[y-1]-c)
a=sorted(a)
b=sorted(b)
print(min(a[0]+b[0],ans))
