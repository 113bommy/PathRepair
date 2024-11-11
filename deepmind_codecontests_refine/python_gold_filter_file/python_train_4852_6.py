a,b=map(int,input().split())
k=180/a
ans=0
p=float("INF")
for i in range(1,a-1):
    if abs(i*k-b)<p:ans=i;p=abs(i*k-b)
print(1,2,a-ans+1)