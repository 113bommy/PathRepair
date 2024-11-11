import sys
input = sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))

v=[]
for s in (1,-1):
    x=a[::]
    hugou=[s*(-1)**i for i in range(n)]
    total=0
    for i in range(n):
        if (total+x[i])*hugou[i]<=0:
            x[i]=hugou[i]-total
        total+=x[i]
    v.append(sum(abs(a[i]-x[i]) for i in range(n)))
print(min(v))
