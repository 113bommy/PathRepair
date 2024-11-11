def is_prime(x):
    # Perform prime number discrimination for odd numbers of 3 or more.
    return pow(2, x - 1, x) == 1

def solve():
    n = int(input())
    ans = n
    if n % 2 == 0:
        ans -= ans // 2
        while n % 2 == 0:
            n //= 2
    d = 3
    while d <= n ** 0.5:
        if is_prime(d) and n % d == 0:
            ans -= ans // d
            while n % d == 0:
                n //= d
        d += 2
    if is_prime(n):
        ans -= ans // n
    print(ans)

solve()