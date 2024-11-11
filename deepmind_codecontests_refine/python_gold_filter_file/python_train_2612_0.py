def get(n,m,a,b,t):
    freq=[0]*(t+1)
    for i in range(n):
        for j in range(m):
            val=abs(i-a)+abs(j-b)
            freq[val]+=1
    return freq
t=int(input())
a=list(map(int,input().split()))
mx=max(a)
f=[0]*(t+1)
for i in a:
    f[i]+=1

b=1
for i in range(1,mx+1):
    if f[i]!=4*i:
        b=i
        break
n=1
a=-1
x=0
y=0
mila=False
while n*n<=t:
    if t%n==0:
        m=t//n
        a=n+m-mx-b
        x,y=n,m
        if  a>0 and a<=n and b>0 and b<=m and f==get(n,m,a-1,b-1,t):
            mila=True
            break
        if  a>0 and a<=m and b>0 and b<=n and f==get(n,m,b-1,a-1,t):
            mila=True
            a,b=b,a
            break
    n+=1
if not mila:
    print(-1)
else:
    print(x,y)
    print(a,b)