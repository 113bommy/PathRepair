n,a,b=map(int,input().split())
v=list(map(int,input().split()))
v.sort()
v=v[::-1]
print(sum(v[:a])/a)
def com(x,y):
    a=1
    b=1
    y=min(y,x-y)
    for i in range(x,x-y,-1):
        a*=i
    for i in range(1,y+1):
        b*=i
    return a//b
ans=0
x=v.count(v[a-1])
y=v[:a].count(v[a-1])
if v[0]!=v[a]:
    ans+=com(x,y)
else:
    for j in range(a,min(b,x)+1):
        ans+=com(x,j)
print(ans)