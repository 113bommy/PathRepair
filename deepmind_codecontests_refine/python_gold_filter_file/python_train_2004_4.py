def solve():
    if not n*a == m * b:
        print("NO")
        return
    ans = [[0 for _ in range(m)] for _ in range(n)]
    colsum = [0]*m
    for i in range(n):
        inds = sorted(range(m), key=lambda x: colsum[x])[:a]
        for j in inds:
            colsum[j] += 1
            ans[i][j] = 1
    print("YES")
    for ai in ans:
        print(*ai, sep="")
    return




t = int(input())
for tt in range(1, t + 1):
    n , m , a, b = [int(i) for i in input().split(" ")]
    solve()