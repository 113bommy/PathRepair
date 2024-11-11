n = int(input())
arr = [[int(i) for i in input().split()] for j in range(n)]
ans = 0
for i in range(n):
    ans += arr[i][i]
    arr[i][i] = 0
    ans += arr[n - 1 - i][i];
    arr[n - i - 1][i] = 0
    ans += arr[n-1-i][n//2];
    arr[n-i-1][n//2] = 0
    ans += arr[n//2][n-1-i];
    arr[n//2][n-1-i] = 0
print(ans)