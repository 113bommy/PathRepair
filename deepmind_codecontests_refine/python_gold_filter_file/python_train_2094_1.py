n, m, k = map(int, input().split())
n1 = n


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


n, k = n // gcd(n, k), k // gcd(n, k)
m, k = m // gcd(m, k), k // gcd(m, k)

if 2 < k:
    print("NO")
elif 2 == k:
    print("YES")
    print(0, 0)
    print(n, 0)
    print(0, m)
else:
    if n * 2 > n1:
        print("YES")
        print(0, 0)
        print(n, 0)
        print(0, m * 2)
    else:
        print("YES")
        print(0, 0)
        print(n * 2, 0)
        print(0, m)