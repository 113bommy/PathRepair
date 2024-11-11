for j in range(int(input())):
    n, p, k = [int(x) for x in input().split()]
    goods = [int(x) for x in input().split()]
    goods.sort()
 
    dp = [0] * n
    dp[0] = goods[0]
    for i in range(1,k):
        dp[i]=goods[i]
    for i in range(k,n):
        dp[i]=goods[i]+dp[i-k]
    for i in range(0, n):
        if dp[i] > p:
            print(i)
            break
    else:
        print(n)
