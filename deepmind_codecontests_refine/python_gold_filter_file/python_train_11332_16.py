from itertools import product

n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

for i, j in product(range(n - m + 1), repeat=2):
    if all(a[i + k][j:j + m] == b[k] for k in range(m)):
        print('Yes')
        break
else:
    print('No')
