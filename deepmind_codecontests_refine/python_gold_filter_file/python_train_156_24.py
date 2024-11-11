n, k = map(int, input().split())
l = list(map(int, input().split()))


i = 1
while i*(i + 1) // 2 < k:
    i += 1

print(l[i - (i * (i + 1) // 2 - k) - 1])