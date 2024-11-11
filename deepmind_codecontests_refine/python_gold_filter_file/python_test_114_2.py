from sys import stdin
input = stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    m = min(a)
    ans = []
    i = -1
    while len(ans) < n // 2:
        i += 1
        if a[i] == m:
            continue
        ans.append((a[i], m))

    for v in ans:
        print(*v)