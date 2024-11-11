read = lambda: map(int, input().split())
n, m = read()
a = {input() for i in range(n)}
b = {input() for i in range(m)}
c = n + m - len(a | b)
if c % 2 == 0:
    print('YES' if n > m else 'NO')
else:
    print('YES' if n + 1 > m else 'NO')