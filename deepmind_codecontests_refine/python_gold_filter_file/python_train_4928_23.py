n, a, b = map(int, input().split())
h = list(map(int, input().split()))

k = sorted(h)

print(k[b] - k[b-1])
