f = lambda k: map(int, input().split(k))
a, u = f(' ')
b, v = f(' ')
h, m = f(':')
t = h * 60 + m - 300
x, y = max(t - v, -1), min(t + u - 1, 1139)
print(y // b - x // b)