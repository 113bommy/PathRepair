try:
    n, m = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    if n >= m:
        print("YES")
    else:
        flag = 0
        dp = [0 for i in range(m+1)]
        for i in arr:
            for j in range(m):
                if dp[j] == 1 and dp[(i+j)%m] == 0:
                    dp[(i+j)%m] = 2
            for j in range(m):
                if dp[j]:
                    dp[j] = 1
            dp[i%m] = 1
        if dp[0]:
            print("YES")
        else:
            print("NO")
except Exception as e:
    print(e)


