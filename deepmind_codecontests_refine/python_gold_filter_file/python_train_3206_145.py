a, b, k = map(int, input().split())

b -= max(0, k - a)
a -= k

print(max(0, a), max(0, b))