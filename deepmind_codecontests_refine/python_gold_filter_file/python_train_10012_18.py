T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    print(min(a[1] - 1, n - 2))
