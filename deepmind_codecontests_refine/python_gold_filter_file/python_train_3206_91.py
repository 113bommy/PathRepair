a, b, k = map(int, input().split())
a = a-k
if a < 0:
    b += a
print(max(a, 0), max(b, 0))