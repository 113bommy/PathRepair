n, k = map(int, input().split())
a = list(map(int, input().split()))
if max(a) - min(a) > k:
    print('NO')
else:
    print('YES')
    m = min(a)
    for num in a:
        print(*[1] * m + list(range(1, 1 + num - m)))
