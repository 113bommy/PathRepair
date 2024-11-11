n, m = map(int, input().split())
MOD = 1000000007
def comb(x, y):
    ret = 1
    for a in range(x, x - y, -1):
        ret *= a
    for b in range(y, 0, -1):
        ret //= b
    return ret

ans = 1
for i in range(2, 100000):
    if i > m:break
    cnt = 0
    while m % i == 0:
        cnt += 1
        m //= i
    ans *= comb(cnt + n - 1, cnt)
if m != 1:
    ans *= comb(n, 1)

print(ans % MOD)