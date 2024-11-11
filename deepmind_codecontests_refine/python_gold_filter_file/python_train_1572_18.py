n = int(input())
arr = list(map(int,input().split()))
arr.sort()
ans = (arr[n-1] - arr[0]) * (arr[2*n - 1] - arr[n])
x  = arr[2*n-1] - arr[0] 
c=0
for i in range(1,n):
    c = x*(arr[i+n-1] - arr[i])
    ans = min(ans,c)
print(ans)