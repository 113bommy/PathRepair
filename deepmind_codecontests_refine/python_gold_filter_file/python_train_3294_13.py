t = int(input())
for o in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    ans = a[0]
    for i in range(1, k):
        ans = max(ans, (a[i] - a[i - 1] + 2)//2)
    ans = max(ans, n - a[k - 1] + 1)
    print(ans)
