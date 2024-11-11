n = int(input())
a = list(map(int, input().split()))
f = 'NO'
for i in range(n):
    if a[a[a[i] - 1] - 1] - 1 == i:
        f = "YES"
print(f)