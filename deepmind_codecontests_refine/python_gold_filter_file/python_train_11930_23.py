n, t, k, d = map(int, input().split())
T1 = (n + k - 1) // k * t

numb = (d + t - 1) // t * k
time = (d + t - 1) // t * t

if numb >= n:
    print('NO')
    exit()

T2 = (n - numb + 2 * k - 1) // (2 * k) * t + d - time + d

print('YES' if T1 > T2 else 'NO')

