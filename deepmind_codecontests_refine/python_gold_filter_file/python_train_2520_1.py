n, k=list(map(int, input().split()))
a=[list(map(int, input().split())) for i in range(n)]
ans=0
for i in range(n-1):
    ans+=(((a[i][0]-a[i+1][0])**2+(a[i][1]-a[i+1][1])**2)**0.5)/50
print(ans*k)