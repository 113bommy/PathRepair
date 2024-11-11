n, n1, n2 = map(int, input().split())
a = sorted(list(map(int, input().split())))
print(a[n2] - a[n2 - 1])