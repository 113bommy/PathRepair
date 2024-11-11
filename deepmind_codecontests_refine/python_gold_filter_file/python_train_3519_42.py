N, K = map(int, input().split())
Vs = list(map(int, input().split()))

ans = 0
for x in range(1, min(K, N)+1):
    for i in range(x+1):
        Ts = Vs[:i] + Vs[N-(x-i):]
        sumOut = sum(Ts)
        Ts.sort()

        for T in Ts[:K-x]:
            if T < 0:
                sumOut -= T
            else:
                break

        ans = max(ans, sumOut)

print(ans)
