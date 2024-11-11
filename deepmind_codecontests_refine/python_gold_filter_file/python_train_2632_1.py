import itertools as it
from functools import reduce

def factor(n):
    """
    >>> factor(2)
    [(2, 1)]

    >>> factor(6)
    [(3, 1), (2, 1)]

    >>> factor(98)
    [(7, 2), (2, 1)]

    >>> factor(1)
    []
    """
    result = []
    i = 2
    while i * i <= n:
        j = 0
        while n % i == 0:
            j += 1
            n //= i
        if j > 0:
            result += [(i, j)]
        i += 1

    if n > 1:
        result += [(n, 1)]
    return result[::-1]


def all_divisors(prime_factorization):
    """
    >>> all_divisors(factor(6))
    [1, 2, 3, 6]

    >>> all_divisors(factor(12))
    [1, 2, 4, 3, 6, 12]

    >>> all_divisors(factor(7))
    [1, 7]

    >>> all_divisors(factor(1))
    [1]
    """
    if len(prime_factorization) == 0:
        return [1]
    result = []
    factor_with_mult = []
    for pfactor in prime_factorization:
        factor_with_mult += [[1]]
        for _ in range(pfactor[1]):
            factor_with_mult[-1] += [factor_with_mult[-1][-1] * pfactor[0]]
    for divisor in it.product(*factor_with_mult):
        result += [reduce(lambda x, y: x * y, divisor)]
    return result


if __name__ == '__main__':
    n = int(input())

    min_result = 10**20
    max_result = 0

    for divisor in all_divisors(factor(n)):
        for div2 in all_divisors(factor(divisor)):
            a = n // divisor + 1
            b = divisor // div2 + 2
            c = div2 + 2
            min_result = min([min_result,
                              c * b + (a - 1) * 2 *
                              (b + c - 2)])
            max_result = max([max_result,
                              c * b + (a - 1) * 2 *
                              (b + c - 2)])
    print(str(min_result) + " " + str(max_result))
