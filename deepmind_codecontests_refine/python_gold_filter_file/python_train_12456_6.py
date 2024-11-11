n = int(input())
a = list(map(int, input().split()))
fl = 'NO'
for i in range(n):
    if a[a[a[i] - 1] - 1] - 1 == i:
        fl = "YES"
print(fl)