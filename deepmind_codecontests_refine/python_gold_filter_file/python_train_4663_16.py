from math import sqrt, ceil

def factors_set(number):
    factors = set()
    for i in range(1, ceil(sqrt(number))+1):
        if number % i == 0:
            factors.add(i)
            factors.add(number // i)
    return factors

N = int(input())

Ks = factors_set(N-1) | factors_set(N)
Ks.remove(1)

ans = 0
for K in Ks:
    N_tmp = N
    while N_tmp % K == 0:
        N_tmp //= K
    if N_tmp % K == 1:
        ans += 1

print(ans)
