n,c=map(int,input().split())
a=list(map(int,input().split()))
f=1
for i in range(1,n):
    if a[i]-a[i-1]<=c:
        f+=1
    else:
        f=1

print(f)