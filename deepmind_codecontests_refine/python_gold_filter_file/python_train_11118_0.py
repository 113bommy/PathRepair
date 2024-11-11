def count(lb, rb):
    assert lb[0] == '1'
    assert rb[0] == '1'
    assert len(lb) == len(rb)
    dp = [1, 0, 0, 0]
    for lc, rc in zip(lb[1:], rb[1:]):
        ndp = [dp[0], 0, 0, 0]
        if rc == '0':
            ndp[1] += dp[1]
            if lc == '1':
                ndp[0] = 0
        else:
            ndp[1] += dp[1] * 2
            ndp[2] += dp[1]
            if lc == '0':
                ndp[1] += dp[0]
                ndp[3] += dp[0]
        if lc == '0':
            ndp[2] += dp[3]
            ndp[3] += dp[3] * 2
        else:
            ndp[3] += dp[3]
        ndp[2] += dp[2] * 3
        dp = ndp
    return sum(dp)


l, r = map(int, input().split())
lb = bin(l)[2:]
rb = bin(r)[2:]
ld = len(lb)
rd = len(rb)
ans = 0
MOD = 10 ** 9 + 7
for d in range(ld, rd + 1):
    tlb = lb if d == ld else '1' + '0' * (d - 1)
    trb = rb if d == rd else '1' * d
    ans = (ans + count(tlb, trb)) % MOD
print(ans)
