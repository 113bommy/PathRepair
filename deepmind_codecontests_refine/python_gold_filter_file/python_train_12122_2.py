n, m = map(int, input().split())
a = list(map(int, input().split()))
b = []
for i in range(1, n+1):
    for j in range(len(a)):
        if a[j] <= i:
            b.append(a[j])
            break
print(*b)
