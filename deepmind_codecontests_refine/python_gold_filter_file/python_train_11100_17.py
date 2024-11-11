n, k = map(int, input().split())
a = list(map(int, input().split()))
if k >= n - 1:
    print(n)
else:
    if a[1] > a[0]:
        index = 1
        max_value = a[1]
    else:
        index = 0
        max_value = a[0]
    for i in range(2, k):
        if a[i] > max_value:
            max_value = a[i]
            index = i
    for i in range(1, n):
        if (i + k - 1) < n and a[(i + k - 1)] > max_value:
            max_value = a[(i + k - 1)]
            index = i + k - 1
        if index == i or (i == 1 and index == 0):
            break
    print(max_value)
