from math import factorial as fac

n = int(input())

a = fac(n) // (fac(5) * fac(n - 5))
b = fac(n) // (fac(6) * fac(n - 6))
c = fac(n) // (fac(7) * fac(n - 7))

res = a+b+c

print(int(res))