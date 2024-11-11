n, a, b = map(int, input().split())
h = sorted(list(map(int, input().split())))
print(h[b] - h[b - 1])
