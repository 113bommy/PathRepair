# region 
# def solve(n, k):
#     dp = [[0] * (n + 1) for _ in range(k + 1)]
#     for i in range(1, n + 1):
#         dp[1][i] = 1
#     for j in range(k):
#         for i in range(1, n + 1):
#             for m in range(i, n + 1, i):
#                 dp[j + 1][m] = (dp[j + 1][m] + dp[j][i]) % mod
#     ans = 0
#     for x in dp[k]:
#         ans += x
#     return ans
# mod = 10**9 + 7
# n, k = map(int, input().split())
# print(solve(n, k) % mod)

# def solve(n):
#     ans = [0]
#     choices = ["a", "b", "c", "d"]
#     def dfs(i, cur):
#         if i == n and i != 0 and cur == "d":
#             ans[0] += 1; return
#         if i > n:
#             return
#         for x in choices:
#             if x == cur:
#                 continue
#             dfs(i + 1, x)
#     dfs(0, "d")
#     return ans[0]
# mod = 10**9 + 7
# n = 10**7
# print(solve(n) % mod)
# n = int(input())

# endregion

def solve(n, a, b):
    flips, i = 0, 0
    while i < n:
        if a[i] != b[i]:
            if i + 1 < n and a[i + 1] != b[i + 1] and a[i] == b[i + 1]:
                i += 1
            flips += 1
            i += 1
        else:
            i += 1
    return flips


# n, a, b = 6, "010101", "001100"
n = int(input())
a = input()
b = input()
print(solve(n, a, b))
