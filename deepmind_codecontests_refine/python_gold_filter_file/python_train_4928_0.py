n, a, b = map(int, input().split())
h = list(map(int, input().split()))

h.sort()

ans = h[b] - h[b-1]

print(ans)