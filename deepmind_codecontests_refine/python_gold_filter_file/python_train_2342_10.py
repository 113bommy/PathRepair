n = int(input())
a = list(map(int,input().split()))
print(a[1]-a[0],a[n-1]-a[0])
for i in range(1,n-1):
    print(min(a[i]-a[i-1],a[i+1]-a[i]),max(a[i]-a[0],a[n-1]-a[i]))
print(a[n-1]-a[n-2],a[n-1]-a[0])