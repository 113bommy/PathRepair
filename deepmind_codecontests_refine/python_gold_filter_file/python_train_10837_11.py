import math
a = input()
b = len(a)
x = math.ceil(b/20)
c = math.ceil(b / x)
y = []
z = c * x - b
cnt = 0
for k in range(x):
    y.append(a[:c])
    a = a[c:]
    if z != 0:
        d = y[k][-1]
        y[k] = y[k][:-1]
        a = d + a
        z -= 1
        y[k] += '*'
        cnt += 1
print(x, c)
print('\n'.join(map(str, y)))

