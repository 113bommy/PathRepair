h = int(input())
w = int(input())
n = int(input())

k = max(h, w)
print((n + k - 1) // k)
