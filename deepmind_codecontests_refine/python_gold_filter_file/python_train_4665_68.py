m = int(input()) // 2
a = sorted(map(int, input().split()))
print(a[m] - a[m - 1])
