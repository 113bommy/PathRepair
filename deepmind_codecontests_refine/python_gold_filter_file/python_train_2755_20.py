n, lst, mn, kf = int(input()), list(map(int, input().split())), 5001, 0
for i in range(1, n-1):
    if lst[i + 1] - lst[i-1] < mn:
        kf = i
        mn = lst[i + 1] - lst[i-1]
del lst[kf]
mn = 0
for i in range(n - 2):
    if lst[i + 1] - lst[i] > mn:
        mn = lst[i + 1] - lst[i]
print(mn)
