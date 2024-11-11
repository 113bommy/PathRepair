n, k = map(int, input().split())
a, b, c, d = map(int, input().split())
if n == 4:
    print(-1)
    exit()
if k < n+1:
    print(-1)
    exit()
print(f"{a} {c}", end=" ")
for i in range(1, n+1):
    if i not in (a, b, c, d):
        print(i, end=" ")
print(f"{d} {b}")
print(f"{c} {a}", end=" ")
for i in range(1, n+1):
    if i not in (a, b, c, d):
        print(i, end=" ")
print(f"{b} {d}")
