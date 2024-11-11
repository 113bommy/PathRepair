w, a, b = map(int, input().split())
c = min(a, b)
d = max(a, b)
print(max(d-(c+w), 0))