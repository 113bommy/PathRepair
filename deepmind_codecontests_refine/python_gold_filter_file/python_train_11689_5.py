# from numba import jit
n = int(input())
a, b, c = map(int, input().split())
x, y, z = map(int, input().split())

maxa = min(a, y) + min(b, z) + min(c, x)
mina = min(a, n - y) + min(b, n - z) + min(c, n - x)

print(n - mina, maxa)