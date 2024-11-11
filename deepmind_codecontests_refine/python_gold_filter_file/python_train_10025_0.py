t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    if a[n - 1] <= d:
        print("YES")
        continue
    if a[0] + a[1] > d: print("NO")
    else: print("YES")