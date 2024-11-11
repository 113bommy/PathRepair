n, m = map(int, input().split())

if n > m + 1 or m > 2 * n + 2:
    print(-1)
elif n >= m:
    print('01' * m + '0' * (n > m))
else:
    print(('10' * n + '1').replace('1', '11', m - n - 1))