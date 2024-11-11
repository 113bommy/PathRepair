n = int(input())
maxv = -2 * 10 ** 9
minv = 2 * 10 ** 9
for i in range(n):
    v = int(input())
    maxv = max(maxv, v - minv)
    minv = min(minv, v)
print(maxv)