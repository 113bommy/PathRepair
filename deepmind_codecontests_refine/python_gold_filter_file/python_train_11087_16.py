n = int(input())
arr = list(map(int,input().split()))
cur = arr[n - 1]
dp= [0] * (n)

for i in range(n - 2 , -1 , - 1):

    if arr[i] > cur :
        dp[i] = 0
        cur = arr[i]

    else:
        dp[i] = cur - arr[i] + 1


print(*dp)