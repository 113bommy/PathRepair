def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    i = 1
    while i <= n // 2:
        print(a[i], a[0])
        i += 1


for _ in range(int(input())):
    solve()
