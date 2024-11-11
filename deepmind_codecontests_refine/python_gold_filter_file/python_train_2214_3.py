def calcCntAtPrefix(a):
    cntAtPrefix = [[0] * (len(a) + 1)]
    for i, x in enumerate(a):
        cntAtPrefix.append(cntAtPrefix[-1][:])
        cntAtPrefix[-1][x] += 1
    return cntAtPrefix

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    cntAtPrefix = calcCntAtPrefix(a)
    cntAtSuffix = calcCntAtPrefix(a[::-1])

    ans = 0
    for j in range(n):
        for k in range(j + 1, n):
            ans += cntAtPrefix[j][a[k]] * cntAtSuffix[n - 1 - k][a[j]]
    print(ans)

for t in range(int(input())):
    solve()
