import sys
input=sys.stdin.readline

n,m=map(int,input().split())
x=[*map(int,input().split())]
seg=[]
for i in range(m):
    a=[*map(int,input().split())]
    seg.append(a)

ans=-1
ansi=[]
for i in range(len(x)):
    tx=x[:]
    oi=[]
    for n,j in enumerate(seg):
        a,b=j
        if not (a-1<=i<=b-1):
            oi.append(n+1)
            for k in range(a-1,b):
                tx[k]-=1
    m=max(tx)-min(tx)
    if m>ans:
        ans=m
        ansi=oi[:]

print(ans)
print(len(ansi))
for i in ansi:
    print(i,end=" ")