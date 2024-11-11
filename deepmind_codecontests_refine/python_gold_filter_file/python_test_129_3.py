def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    a = []
    vis = [0] * (1 + n)
    for i in arr:
        if i <= n and not vis[i]:
            vis[i] = 1
        else:
            a.append(i)
    # print(a)
    a.sort()
    j = 0
    for i in range(1, n + 1):
        if not vis[i]:
            if a[j] < 2 *i + 1:
                return -1
            j += 1
    return j




t = int(input())
while t:
    print(solve())
    t -= 1


