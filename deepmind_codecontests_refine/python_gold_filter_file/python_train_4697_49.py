a = list(map(int, input().split()))

a.sort()

print(((a[2]) - (a[0] + a[1]) + 1) if (a[2] - (a[0] + a[1])) >= 0 else 0)
