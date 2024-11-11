n = int(input())
a = list(map(int, input().split()))

max_distance = 0
index_max = a.index(max(a))
index_min = a.index(min(a))

if index_min < index_max:
    if index_min + 1 > n - index_max - 1:
        a[0], a[index_min] = a[index_min], a[0]
    else:
        a[-1], a[index_max] = a[index_max], a[-1]
else:
    if index_max + 1 > n - index_min - 1:
        a[0], a[index_max] = a[index_max], a[0]
    else:
        a[-1], a[index_min] = a[index_min], a[-1]
index_max = a.index(max(a))
index_min = a.index(min(a))
print(max(index_max, index_min) - min(index_max, index_min))