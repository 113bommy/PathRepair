from sys import stdin
input=stdin.readline
N=2*(10**16)+5
x=[0]
y=[0]
x[0],y[0],x1,y1,x2,y2=map(int,input().split())
a,b,t=map(int,input().split())
while x[-1]<N and y[-1]<N:
    x.append(x1*x[-1]+x2)
    y.append(y1*y[-1]+y2)
ans=0
for i in range(len(x)):
    for j in range(len(x)):
        d1 = abs(x[i]-a)+abs(y[i]-b)
        d2 = abs(x[i]-x[j])+abs(y[i]-y[j])
        if d1+d2<=t:
            ans=max(ans,abs(j-i)+1)
print(ans)