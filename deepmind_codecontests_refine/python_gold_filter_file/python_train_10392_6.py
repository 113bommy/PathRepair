n=int(input())
xy=[list(map(int,input().split())) for _ in range(n)]
m=39
ans=[]
if sum(xy[0])%2==0:ans.append(1)
for i in range(m):
    ans.append(2**i)
c=sum(xy[0])%2
for x,y in xy:
    if (x+y)%2!=c:exit(print(-1))
print(len(ans))
print(*ans[::-1])
def chk(s):
    a=[]
    for d in ans[::-1]:
        if abs(s-d)<abs(s+d):
            a.append(-1)
            s-=d
        else:
            a.append(1)
            s+=d
    return a
xpy,xmy=[],[]
for x,y in xy:
    xpy=chk(x+y)
    xmy=chk(x-y)
    s=[]
    for p,m in zip(xpy,xmy):
        if p==1 and m==1:s.append('L')
        if p==-1 and m==-1:s.append('R')
        if p==1 and m==-1:s.append('D')
        if p==-1 and m==1:s.append('U')
    print(*s,sep='')