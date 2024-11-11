n = int(input())
a = list(map(int,input().split()))
a.sort(reverse=True)
ans = a[n-1]
for i in range(1,n):
    if a[0]%a[i] != 0 or a[i-1]==a[i]:
        ans = a[i]
        break
print(ans,a[0])