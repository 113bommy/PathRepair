import sys
from collections import defaultdict


def eratosthenes_generator():
    yield 2
    n = 3
    h = {}
    while True:
        m = n
        if n in h:
            b = h[n]
            m += 2 * b
            while m in h:
                m += 2 * b
            h[m] = b
            del h[n]
        else:
            m += 2 * n
            while m in h:
                m += 2 * n
            h[m] = n
            yield n
        n += 2


gen = eratosthenes_generator()
p = 0
primes = []
for p in gen:
    if p > 2154:
        break
    primes.append(p)

prime_pairs = {1: 1, p: p * p, p * p: p}
for p in gen:
    if p > 100000:
        break
    p2 = p * p
    prime_pairs[p] = p2
    prime_pairs[p2] = p

n, *sss = map(int, sys.stdin.buffer.read().split())
normalized = defaultdict(int)
over_pairs = {}
frac_pairs = {}
ans = 0
for s in sss:
    # sを2154までの素数で全て割る → ～10^5 までの単一の素数またはその2乗以外は、10^10 までの範囲にペアは存在し得ない
    frac = 1  # 2154までの素因数について、立方数とならない端数を掛け合わせたもの
    pair = 1  # 2154までの素因数について、立方数となるためにペアに求められる因数
    for p in primes:
        if s < p:
            break
        x = 0
        d, m = divmod(s, p)
        while m == 0:
            x += 1
            s = d
            d, m = divmod(s, p)
        x %= 3
        if x == 1:
            frac *= p
            pair *= p ** 2
        elif x == 2:
            frac *= p ** 2
            pair *= p
    if s > 2154 and s not in prime_pairs:
        ans += 1
        continue
    frac_pairs[frac] = pair
    normalized[s, frac] += 1

if (1, 1) in normalized:
    ans += 1
    del normalized[1, 1]

tmp = 0
for (s, frac), cnt in normalized.items():
    pair = (prime_pairs[s], frac_pairs[frac])
    if pair not in normalized:
        tmp += cnt * 2
    else:
        tmp += max(cnt, normalized[pair])
ans += tmp // 2

print(ans)
