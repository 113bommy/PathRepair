import sys
input=sys.stdin.readline

n,k=list(map(int,input().split()))
c=[]
d=[]
e=[]
for i in range(n):
    t,a,b=list(map(int,input().split()))
    if a==1 and b==1:
        c.append(t)
    if a==0 and b==1:
        d.append(t)
    if a==1 and b==0:
        e.append(t)
d.sort()
e.sort()
x=min(len(d),len(e))
for i in range(x):
    c.append(d[i]+e[i])
c.sort()
if len(c)<k:
    print(-1)
else:
    print(sum(c[:k]))