import sys
from array import array  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def get_primes(n: int):
    from itertools import chain
    from array import array
    primes = [3, 4]
    is_prime = (array('b', (0, 0, 1, 1, 0, 1, 0)) +
                array('b', (1, 0, 0, 0, 1, 0)) * ((n - 1) // 6))

    for i in chain.from_iterable((range(5, n + 1, 6), range(7, n + 1, 6))):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * 3, n + 1, i * 2):
                is_prime[j] = 0

    return is_prime, primes


n = int(input())
a = list(map(int, input().split()))
if all(a):
    print('YES')
    exit()

_, primes = get_primes(n)
for p in primes:
    if n % p != 0:
        continue
    m = n // p
    for i in range(m):
        if all(a[i::m]):
            print('YES')
            exit()
print('NO')
