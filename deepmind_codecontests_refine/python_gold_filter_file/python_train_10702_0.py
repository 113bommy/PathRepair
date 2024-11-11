n = int(input())
a = list(map(int, input().split()))
max_a = 2 ** 20
MOD = 10 ** 9 + 7

ru = [0] * (n + 1)
for i in range(n):
    ru[i + 1] = ru[i] ^ a[i]


if ru[-1] != 0:
    # 0, ru[-1], 0, ru[-1], 0, ..., ru[-1]
    dp = [0] * (max_a)
    dp[0] = 1
    tot_ex0 = 0
    for i in range(n):
        if i == n - 1:
            print(dp[0])
            exit()
        if ru[i + 1] == 0:
            dp[0] += tot_ex0
            dp[0] %= MOD
        elif ru[i + 1] == ru[-1]:
            dp[ru[i + 1]] += dp[0]
            dp[ru[i + 1]] %= MOD
            tot_ex0 += dp[0]
            tot_ex0 %= MOD
else:
    # 0, x, 0, x, 0, x, ..., 0 (x != 0)
    dp = [0] * max_a
    dq = [1] * max_a
    set_evaled = [0] * max_a
    times = 0
    ans = 0
    for i in range(n):
        if i == n - 1:
            ans = sum(dp)
            break
        elif ru[i + 1] == 0:
            # これを遅延評価する
            # for j in range(max_a):
            #     dq[j] += dp[j]
            times += 1
        else:
            dq[ru[i + 1]] += (times - set_evaled[ru[i + 1]]) * dp[ru[i + 1]]
            dq[ru[i + 1]] %= MOD
            set_evaled[ru[i + 1]] = times
            dp[ru[i + 1]] += dq[ru[i + 1]]
            dp[ru[i + 1]] %= MOD
    # 0, 0, 0, 0, 0, 0, ..., 0
    cnt_0 = sum([1 for i in range(n) if ru[i + 1] == 0])
    ans = (ans + pow(2, cnt_0 - 1, MOD)) % MOD
    print(ans)