n,m=map(int,input().split())
a=list(map(int,input().split()))
s=0
for j in range(n):
    s=s+a[j]
s=s+m
e=s/n
t=0
for i in range(n):
    if e-a[i]>=0:
       a[i]=e-a[i]
    else:
        print(-1)
        t=1
        break
if t==0:
    print(*a,sep="\n")