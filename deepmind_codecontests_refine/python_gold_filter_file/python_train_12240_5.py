n, m, n = map(int, input().split())

p = (n - 1) // 2
y = (p // m) + 1
x = (p % m) + 1

if n % 2 == 0:
    print(y, x, 'R')
if n % 2 == 1:
    print(y, x, 'L')
