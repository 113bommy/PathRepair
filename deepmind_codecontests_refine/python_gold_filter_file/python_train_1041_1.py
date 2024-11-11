n = int(input())
a = [int(input()) for i in range(n)]

def lis_linear(a, n):
    dp = [0 for i in range(n)]
    longest = 1
    for i in range(n):
        max_val = 1
        for j in range(i):
            if a[j] < a[i] and max_val < dp[j] + 1:
                max_val = dp[j] + 1
        dp[i] = max_val
        if dp[i] > longest: longest = dp[i]
    return longest

def lis_binary(a, n):
    tail = [a[0]]
    for i in range(1, n):
        if a[i] > tail[-1]:
            tail.append(a[i])
            continue
        for j in range(len(tail)):
            if a[i] <= tail[j]:
                tail[j] = a[i]
                break
    return len(tail)

print(lis_binary(a, n))
