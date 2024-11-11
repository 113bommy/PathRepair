def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    for i in range(n // 2):
        print(a[n - 1 - i], a[0])


t = int(input())
for _ in range(t):
    solve()
