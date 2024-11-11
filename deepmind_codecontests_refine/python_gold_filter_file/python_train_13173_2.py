import math


def get_primes(prime_supr):

    is_prime = [0]*2 + [1]*prime_supr

    for i in range(2,int(math.sqrt(prime_supr)) + 1):
        if is_prime[i]:
            for j in range(i * i, prime_supr + 1, i):
                is_prime[j] = 0

    return is_prime

get_int = lambda: map(int, input().split())

r, c = get_int()
ans = 0
tmp = 0
for i in range(c):
    if '0' not in input():
        ans = max(ans, tmp)
        tmp = 0
    else:
        tmp += 1

print(max(ans,tmp))
