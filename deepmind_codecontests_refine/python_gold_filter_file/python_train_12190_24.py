R = lambda: list(map(int, input().split(' ')))
n, m = R()
x, d = [], []
for i in range(m):
    xi, di = R()
    x.append(xi)
    d.append(di)
b_max = n * (n - 1) // 2
b_min = n**2 // 4
b = [di * (b_max if di > 0 else b_min) for di in d]
print((n * sum(x) + sum(b)) / n)