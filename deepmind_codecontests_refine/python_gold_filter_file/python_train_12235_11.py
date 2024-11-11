n = int(input())

a = 2 * 3 * (4** (n - 3))
b = (n - 3) * 3 * 3 * (4 ** (n - 4))
res = (a + b) * 4
print(int(res))
