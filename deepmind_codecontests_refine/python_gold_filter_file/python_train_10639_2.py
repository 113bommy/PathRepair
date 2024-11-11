     
A = [(0, 0)]
inf = 999999999999
n, m = map(int, input().split())
 
for i in range(1, n+1):
    x, s = map(int, input().split())
    A.append((max(0, x-s), min(m, x+s)))
dp = [inf] * (m+1)
dp[0] = 0
A = sorted(A)
 
for p in range(1, m+1):    
    for i in range(1, n+1):
 
        a, b = A[i]
 
        if p >= a and p <= b:
            dp[p] = dp[p-1]
        elif p < a:
            pwr = a - p
            dp[p] = min(dp[p], pwr + dp[max(0,a-pwr-1)], p)
        elif p > b:
            pwr = p - b
            dp[p] = min(dp[p], pwr + dp[max(a-pwr-1,0)], p)
 
print(dp[m])