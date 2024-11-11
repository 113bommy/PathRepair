''' CODED WITH LOVE BY SATYAM KUMAR '''

from sys import stdin, stdout
import heapq
import cProfile, math
from collections import Counter, defaultdict, deque
from bisect import bisect_left, bisect, bisect_right
import itertools
from copy import deepcopy
from fractions import Fraction
import sys, threading
import operator as op
from functools import reduce
import sys

sys.setrecursionlimit(10 ** 6)  # max depth of recursion
threading.stack_size(2 ** 27)  # new thread will get stack of such size
fac_warm_up = False
printHeap = str()
memory_constrained = False
P = 10 ** 9 + 7


class MergeFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n
        self.lista = [[_] for _ in range(n)]

    def find(self, a):
        to_update = []
        while a != self.parent[a]:
            to_update.append(a)
            a = self.parent[a]
        for b in to_update:
            self.parent[b] = a
        return self.parent[a]

    def merge(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.num_sets -= 1
        self.parent[b] = a
        self.size[a] += self.size[b]
        self.lista[a] += self.lista[b]

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets


def display(string_to_print):
    stdout.write(str(string_to_print) + "\n")


def prime_factors(n):  # n**0.5 complex
    factors = dict()
    for i in range(2, math.ceil(math.sqrt(n)) + 1):
        while n % i == 0:
            if i in factors:
                factors[i] += 1
            else:
                factors[i] = 1
            n = n // i
    if n > 2:
        factors[n] = 1
    return (factors)


def all_factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))


def fibonacci_modP(n, MOD):
    if n < 2: return 1
    return (cached_fn(fibonacci_modP, (n + 1) // 2, MOD) * cached_fn(fibonacci_modP, n // 2, MOD) + cached_fn(
        fibonacci_modP, (n - 1) // 2, MOD) * cached_fn(fibonacci_modP, (n - 2) // 2, MOD)) % MOD


def factorial_modP_Wilson(n, p):
    if (p <= n):
        return 0
    res = (p - 1)
    for i in range(n + 1, p):
        res = (res * cached_fn(InverseEuler, i, p)) % p
    return res


def binary(n, digits=20):
    b = bin(n)[2:]
    b = '0' * (digits - len(b)) + b
    return b


def is_prime(n):
    """Returns True if n is prime."""
    if n < 4:
        return True
    if n % 2 == 0:
        return False
    if n % 3 == 0:
        return False
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += w
        w = 6 - w
    return True


def generate_primes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while p * p <= n:
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    return prime


factorial_modP = []


def warm_up_fac(MOD):
    global factorial_modP, fac_warm_up
    if fac_warm_up: return
    factorial_modP = [1 for _ in range(fac_warm_up_size + 1)]
    for i in range(2, fac_warm_up_size):
        factorial_modP[i] = (factorial_modP[i - 1] * i) % MOD
    fac_warm_up = True


def InverseEuler(n, MOD):
    return pow(n, MOD - 2, MOD)


def nCr(n, r, MOD):
    global fac_warm_up, factorial_modP
    if not fac_warm_up:
        warm_up_fac(MOD)
        fac_warm_up = True
    return (factorial_modP[n] * (
            (pow(factorial_modP[r], MOD - 2, MOD) * pow(factorial_modP[n - r], MOD - 2, MOD)) % MOD)) % MOD


def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))


memory = dict()


def clear_cache():
    global memory
    memory = dict()


def cached_fn(fn, *args):
    global memory
    if args in memory:
        return memory[args]
    else:
        result = fn(*args)
        memory[args] = result
        return result


def ncr(n, r):
    return math.factorial(n) / (math.factorial(n - r) * math.factorial(r))


def binary_search(i, li):
    fn = lambda x: li[x] - x // i
    x = -1
    b = len(li)
    while b >= 1:
        while b + x < len(li) and fn(b + x) > 0:  # Change this condition 2 to whatever you like
            x += b
        b = b // 2
    return x


# -------------------------------------------------------------- MAIN PROGRAM


TestCases = True
optimise_for_recursion = True  # Can not be used clubbed with TestCases WHen using recursive functions, use Python 3


def make(x):
    global li
    if x==2: return '11337', 2
    ind = bisect_left(li, x)
    if li[ind]==x:
        return '1' + '3'*(ind+2) + '7', ind+2
    else:
        ind -=1
        x, y = make(x - li[ind])
        z = '1' + '3'*(ind+2-y) + x
        return z, ind+2


def main():
    global li
    n = get_int()
    li = [(i*(i-1))//2 for i in range(2, 10**5)]
    print(make(n)[0])



# --------------------------------------------------------------------- END=


if TestCases:
    for i in range(get_int()):
        main()
else:
    main() if not optimise_for_recursion else threading.Thread(target=main).start()
