n = int(input())
arr = list(map(int,input().split()))
ans = 0
for i in range(n):
    k = 0
    for j in range(i,n):
        k ^= arr[j]
        ans = max(ans, k)
print(ans)
