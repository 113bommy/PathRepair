n = int(input())
lst = list(map(int, input().split()))

k = 1
r = 0
for i in range(0, n - 1):
    if lst[i] < lst[i + 1]:
        k += 1
    elif lst[i] >= lst[i + 1]:
        if r < k:
            r = k
        k = 1

print(max(k, r))