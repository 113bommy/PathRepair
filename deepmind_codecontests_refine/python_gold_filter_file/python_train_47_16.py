n = int(input())
x, h = [], []
for i in range(n):
    xi, hi = map(int, input().split())
    x += [xi]
    h += [hi]
lx = x[0]
cnt = min(n, 2)
for i in range(1, n - 1):
    if x[i] - lx > h[i]:
        cnt += 1
        lx = x[i]
    elif x[i + 1] - x[i] > h[i]:
        cnt += 1
        lx = x[i] + h[i]
    else:
        lx = x[i]
print(cnt)
