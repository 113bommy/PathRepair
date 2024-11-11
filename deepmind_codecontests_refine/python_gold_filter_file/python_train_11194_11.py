n, a, b = map(int, input().split())
k = a * b - n
if k < 0: print(-1)
else:
    p = list(map(str, range(1, n + 1))) + ['0'] * k
    for i in range(a):
        t = p[i * b:i * b + b]
        print(' '.join(t if b & 1 or i & 1 else t[::-1]))