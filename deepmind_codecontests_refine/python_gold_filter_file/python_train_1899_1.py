T = int(input())
for t in range(T):
    d, m = map(int, input().split())
    bd = bin(d)[2:]
    lbd = len(bd)
    ans = d - (1 << (lbd - 1)) + 1
    for b in range(len(bd) - 1, 0, -1):
        q = 1 << (b - 1)
        ans = (ans + ans * q + q) % m

    print(ans % m)
