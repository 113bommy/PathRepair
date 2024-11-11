from sys import stdin, stdout

n = int(stdin.readline())
s = stdin.readline().strip()
length = list(map(int, stdin.readline().strip().split()))
bn = [2 ** i for i in range(10 ** 3 + 2)]

dp = [0 for i in range(n + 10)]
dp[0] = 1
ans = [0, 1, 0]

dp1 = [0 for i in range(n + 5)]
dp1[0] = 1

for i in range(1, n):
    label = 1
    cnt = min(i + 1, length[ord(s[i]) - ord('a')])
    
    
    
    
    while label:
        label = 0
        for ind in range(i - cnt + 1, i + 1):
            if length[ord(s[ind]) - ord('a')] < cnt:
                cnt -= 1
                label = 1
                break
            
            
            
    
    dp1[i] = dp1[i - cnt] + 1
    ans[1] = max(ans[1], cnt)
    
    if cnt == i + 1:
        dp[i] = bn[cnt - 1]
    else:
        for j in range(1, cnt + 1):
            dp[i] += dp[i - j]

ans[0] = (dp[n - 1] % (10 ** 9 + 7))
ans[2] = dp1[n - 1]

stdout.write('\n'.join(list(map(str, ans))))