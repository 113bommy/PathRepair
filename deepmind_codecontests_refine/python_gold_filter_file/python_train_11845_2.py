# 動作テスト
# ACならAtCoder LibraryのPython版Convolution翻訳完了

class convolution:
    def __init__(self, a: list, b: list, mod: int):
        self.a, self.b = a, b
        self.n, self.m = len(a), len(b)
        self.MOD = mod
        self.g = self.__primitive_root_constexpr()
    
    def convolution(self) -> list:
        n, m = self.n, self.m
        a, b = self.a, self.b
        if not n or not m: return []
        if min(n, m) <= 60:
            if n < m:
                n, m = m, n
                a, b = b, a
            ans = [0] * (n + m - 1)
            for i in range(n):
                for j in range(m):
                    ans[i + j] += a[i] * b[j] % self.MOD
                    ans[i + j] %= self.MOD
            return ans
        z = 1 << self.ceil_pow2(n + m - 1)
        a = self.resize(a, z)
        a = self.butterfly(a)
        b = self.resize(b, z)
        b = self.butterfly(b)
        for i in range(z): a[i] = a[i] * b[i] % self.MOD
        a = self.butterfly_inv(a)
        a = a[:n + m - 1]
        iz = self.inv(z)
        a = [x * iz % self.MOD for x in a]
        return a

    def butterfly(self, a: list) -> list:
        n = len(a)
        h = self.ceil_pow2(n)
        first = True
        sum_e = [0] * 30
        m = self.MOD
        if first:
            first = False
            es, ies = [0] * 30, [0] * 30
            cnt2 = self.bsf(m - 1)
            e = self.mypow(self.g, (m - 1) >> cnt2); ie = self.inv(e)
            for i in range(cnt2, 1, -1):
                es[i - 2] = e
                ies[i - 2] = ie
                e = e * e % m
                ie = ie * ie % m
            now = 1
            for i in range(cnt2 - 2):
                sum_e[i] = es[i] * now % m
                now = now * ies[i] % m
        for ph in range(1, h + 1):
            w = 1 << (ph - 1); p = 1 << (h - ph)
            now = 1
            for s in range(w):
                offset = s << (h - ph + 1)
                for i in range(p):
                    l = a[i + offset] % m
                    r = a[i + offset + p] * now % m
                    a[i + offset] = (l + r) % m
                    a[i + offset + p] = (l - r) % m
                now = now * sum_e[self.bsf(~s)] % m
        return a

    def butterfly_inv(self, a: list) -> list:
        n = len(a)
        h = self.ceil_pow2(n)        
        first = True
        sum_ie = [0] * 30
        m = self.MOD
        if first:
            first = False
            es, ies = [0] * 30, [0] * 30
            cnt2 = self.bsf(m - 1)
            e = self.mypow(self.g, (m - 1) >> cnt2); ie = self.inv(e)
            for i in range(cnt2, 1, -1):
                es[i - 2] = e
                ies[i - 2] = ie
                e = e * e % m
                ie = ie * ie % m
            now = 1
            for i in range(cnt2 - 2):
                sum_ie[i] = ies[i] * now % m
                now = es[i] * now % m
        for ph in range(h, 0, -1):
            w = 1 << (ph - 1); p = 1 << (h - ph)
            inow = 1
            for s in range(w):
                offset = s << (h - ph + 1)
                for i in range(p):
                    l = a[i + offset] % m
                    r = a[i + offset + p] % m
                    a[i + offset] = (l + r) % m
                    a[i + offset + p] = (m + l - r) * inow % m
                inow = sum_ie[self.bsf(~s)] * inow % m
        return a

    @staticmethod
    def resize(array: list, sz: int) -> list:
        new_array = array + [0] * (sz - len(array))
        return new_array
    @staticmethod
    def ceil_pow2(n: int) -> int:
        x = 0
        while (1 << x) < n: x += 1
        return x
    @staticmethod
    def bsf(n: int) -> int:
        return (n & -n).bit_length() - 1
    def inv(self, x: int):
        if self.__is_prime_constexpr():
            assert x
            return self.mypow(x, self.MOD - 2)
        else:
            eg = self.__inv_gcd(x)
            assert eg[0] == 1
            return eg[1]
    def mypow(self, x: int, n: int) -> int:
        assert 0 <= n
        r = 1
        while n:
            if n & 1: r = r * x % self.MOD
            x = x * x % self.MOD
            n >>= 1
        return r
    # private
    def __is_prime_constexpr(self) -> bool:
        n = self.MOD
        if n <= 1: return False
        if n == 2 or n == 7 or n == 61: return True
        if n % 2 == 0: return False
        d = n - 1
        while d % 2 == 0: d //= 2
        for a in [2, 7, 61]:
            t = d
            y = self.__pow_mod_constexpr(a, t, n)
            while t != n - 1 and y != 1 and y != n - 1:
                y = y * y % n
                t <<= 1
            if y != n - 1 and t % 2 == 0: return False
        return True
    def __pow_mod_constexpr(self, x: int, n: int, m: int) -> int:
        if m == 1: return 0
        _m = m; r = 1; y = self.__safe_mod(x, m)
        while n:
            if n & 1: r = (r * y) % _m
            y = (y * y) % _m
            n >>= 1
        return r
    def __safe_mod(self, x: int, m: int) -> int:
        x %= m
        if x < 0: x += m
        return x
    def __inv_gcd(self, a: int) -> tuple:
        b = self.MOD; a = safe_mod(a, b)
        if a == 0: return (b, 0)
        s = b; t = a; m0 = 0; m1 = 1
        while t:
            u = s // t
            s -= t * u
            m0 -= m1 * u
            tmp = s; s = t; t = tmp; tmp = m0; m0 = m1; m1 = tmp
        if m0 < 0: m0 += b // s
        return (s, m0)
    def __primitive_root_constexpr(self) -> int:
        m = self.MOD
        if m == 2: return 1
        if m == 167772161: return 3
        if m == 469762049: return 3
        if m == 754974721: return 11
        if m == 998244353: return 3
        divs = [0] * 20
        divs[0] = 2
        cnt = 1
        x = (m - 1) // 2
        while x % 2 == 0: x //= 2
        i = 3
        while i * i <= x:
            if x % i == 0:
                divs[cnt] = i; cnt += 1
                while x % i == 0:
                    x //= i
            i += 2
        if x > 1: divs[cnt] = x; cnt += 1
        g = 2
        while True:
            ok = True
            for i in range(cnt):
                if self.__pow_mod_constexpr(g, (m - 1) // divs[i], m) == 1:
                    ok = False
                    break
            if ok: return g
            g += 1

#----------convolution class end----------

# Date [ 2020-09-11 15:37:28 ]
# Problem [ e.py ]
# Author Koki_tkg

import sys
# import math
# import bisect
# import numpy as np
# from decimal import Decimal
# from numba import njit, i8, u1, b1 #JIT compiler
# from itertools import combinations, product
# from collections import Counter, deque, defaultdict

# sys.setrecursionlimit(10 ** 6)
MOD = 998244353
INF = 10 ** 9
PI = 3.14159265358979323846

def read_str():      return sys.stdin.readline().strip()
def read_int():      return int(sys.stdin.readline().strip())
def read_ints():     return map(int, sys.stdin.readline().strip().split())
def read_ints2(x):   return map(lambda num: int(num) - x, sys.stdin.readline().strip().split())
def read_str_list(): return list(sys.stdin.readline().strip().split())
def read_int_list(): return list(map(int, sys.stdin.readline().strip().split()))
def GCD(a: int, b: int) -> int: return b if a%b==0 else GCD(b, a%b)
def LCM(a: int, b: int) -> int: return (a * b) // GCD(a, b)

def Main():
    n, m = read_ints()
    a = read_int_list()
    b = read_int_list()
    a = [x % MOD for x in a]
    b = [x % MOD for x in b]
    cnv = convolution(a, b, MOD)
    ans = cnv.convolution()
    print(*ans)

if __name__ == '__main__':
    Main()