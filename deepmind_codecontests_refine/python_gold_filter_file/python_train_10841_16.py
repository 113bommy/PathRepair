n = int(input())
a = [int(i) for i in input().split()]
if a[0] != a[-1]:
    print(n - 1)
else:
    for i in range(n):
        if a[i] != a[0]:
            break
    for j in range(n - 1, -1, -1):
        if a[j] != a[-1]:
            break
    print(max(n - i - 1, j))
