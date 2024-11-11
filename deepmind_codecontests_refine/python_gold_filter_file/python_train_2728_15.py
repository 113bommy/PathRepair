t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    idx = [i for i in range(n - 1) if abs(a[i + 1] - a[i]) >= 2]

    if idx:
        print('YES')
        print(idx[0] + 1, idx[0] + 2)
    else:
        print('NO')
