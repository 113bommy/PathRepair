P = int(input())
A = [int(_) for _ in input().split()]


class Factorial:
    def __init__(self, max_fact, mod):
        #mod should be prime number
        #using homogeneous_product(n,r), max_fact ≧ max(n+r-1)
        f = [1] * (max_fact + 1)
        for idx in range(2, max_fact + 1):
            f[idx] = f[idx - 1] * idx
            f[idx] %= mod
        fi = [pow(f[-1], mod - 2, mod)]
        for idx in range(max_fact, 0, -1):
            fi += [fi[-1] * idx % mod]
        fi = fi[::-1]
        self.mod = mod
        self.f = f
        self.fi = fi

    def factorial(self, n):
        return self.f[n]

    def factorial_inverse(self, n):
        return self.fi[n]

    def combination(self, n, r):
        f = self.f
        fi = self.fi
        return f[n] * fi[r] * fi[n - r] % self.mod

    def permutation(self, n, r):
        return self.f[n] * self.fi[n - r] % self.mod

    def homogeneous_product(self, n, r):
        f = self.f
        fi = self.fi
        return f[n + r - 1] * fi[r] * fi[n - 1] % self.mod


max_fact = P - 1
mod = P
fact_instance = Factorial(max_fact, mod)
comb = fact_instance.combination
perm = fact_instance.permutation
combrep = fact_instance.homogeneous_product

ans = [0] * P
for i, a in enumerate(A):
    if a:
        #1-(x-i)^(P-1)
        ans[0] += 1
        for r in range(P):
            ans[r] -= comb(P - 1, r) * pow(-i, P - 1 - r, P)
            ans[r] %= mod
print(*ans)
