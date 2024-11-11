n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
b.sort()
a.sort()
pos=0
mn=float('inf')
while pos<n:
    if mn!=float('inf'):
        break
    for j in range(n):
        x=(b[j]-a[pos])%m
        temp=[(a[i]+x)%m for i in range(n)]
        if sorted(temp)==b:
            mn=min(mn,x)
    pos+=1
print(mn)