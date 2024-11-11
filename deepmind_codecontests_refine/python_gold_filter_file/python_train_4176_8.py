import math
n, m, k = list(map(int, input().split()))
s = n * m / k
if 2*n*m % k != 0:
    print('NO')
else:
    if k % 2 == 0:
        k = k // 2
        g = math.gcd(k, n)
        dk = k // g
        a = n // g
        b = m // dk
    else:
        g = math.gcd(k, n)
        dk = k // g
        a = n // g
        b = m // dk
        if a * 2 < n:
            a *= 2
        else:
            b *= 2
    print('YES')
    print(0, 0)
    print(a, 0)
    print(0, b)
