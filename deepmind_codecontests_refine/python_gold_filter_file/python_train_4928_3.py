n, a, b = map(int, input().split())
ar = list(map(int, input().split()))
ar.sort()
if ar[b - 1] == ar[b]:
    print(0)
else:
    print(ar[b] - ar[b - 1])