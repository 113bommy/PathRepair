def power(a, n, p):
    if n == 0:
        return 1
    x = power(a, n//2, p)
    x = (x * x) % p
    if n % 2 == 1:
        x = (x * a) % p
    return x % p


def gcd_extended(a, b):
    # Base Case
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = gcd_extended(b % a, a)
    # Update x and y using results of recursive call
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y


def poly_hash(s, p, q):
    d = 1
    res = 0
    for c in s[::-1]:
        res += (int(c) * d) % p
        d = (d * q) % p
    return res


def slightly_similar(n, k, s):
    ls = map(int, list(s))
    s_inv = ''.join([str(1 - int(c)) for c in s])
    # print(s_inv)

    p = 998244353
    q = 3
    # q_inv = gcd_extended(q, p)[1] % p

    # powers = [1]
    # inv_powers = [1]
    # r = 10 ** 6
    # for i in range(r):
    #     powers.append((powers[-1] * q) % p)
    #     inv_powers.append((inv_powers[-1] * q_inv) % p)

    # collecting hashes of substrings of s
    h = poly_hash(s_inv[:k], p, q)
    hashes = {h}
    l = 0
    r = k
    while r < n:
        # h = (h * q - int(s_inv[l]) * power(q, k, p) + int(s_inv[r])) % p
        h = (h * q - int(s_inv[l]) * q_k + int(s_inv[r])) % p
        hashes.add(h)
        l += 1
        r += 1

    # finding 1st hash not in s
    a = 0
    b = bin(a)[2:]
    while len(b) <= k:
        if poly_hash(b, p, q) not in hashes:
            # print('found it!')
            # print(b)
            # print(poly_hash(b, p, q))
            # print(hashes)
            return ['YES', '0' * (k - len(b)) + b]
        a += 1
        b = bin(a)[2:]
    return ['NO']


t = int(input())
# t = 1
for _ in range(t):
    n, k = map(int, input().split())
    s = input()

    p = 998244353
    q = 3
    q_k = power(q, k, p)

    ans = slightly_similar(n, k, s)
    for x in ans:
        print(x)
