INF = float('inf')
n = int(input())
aaa = [0, 0] + list(map(int, input().split()))
dp = [[0 for _ in range(n+1)] for i in range(2)]
vis = [[0 for _ in range(n+1)] for i in range(2)]
rs = [0] * (n-1)

def di(d): return 0 if d == 1 else 1


def solve(x, d):
    if dp[di(d)][x]:
        return dp[di(d)][x]

    if vis[di(d)][x]:
        return INF

    ni = x + aaa[x] * d
    if ni < 1 or ni > n:
        return aaa[x]

    vis[di(d)][x] = 1
    r = aaa[x] + solve(ni, -d)
    vis[di(d)][x] = 0
    return r


for D in [1, -1]:
    for x in range(2, n+1):
        d = D
        if dp[di(d)][x]:
            continue

        ni = x + aaa[x] * d
        path = [x]
        values = [aaa[x]]
        while ni > 1 and ni <= n:
            path.append(ni)
            if dp[di(-d)][ni]:
                values.append(dp[di(-d)][ni])
                d *= -1
                break

            if vis[di(d)][ni]:
                values.append(INF)
                d *= -1
                break

            vis[di(d)][ni] = 1
            values.append(aaa[ni])

            d *= -1
            ni = ni + aaa[ni] * d


        if ni == 1:
            continue

        for i in range(len(values)-2, -1, -1):
            values[i] = values[i] + values[i+1]

        while path:
            dp[di(d)][path.pop()] = values.pop()
            d *= -1


for i in range(1, n):
    aaa[1] = i
    res = solve(1, 1)
    rs[i-1] = res if res < INF else -1


print('\n'.join(map(str, rs)))