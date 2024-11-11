n = int(input())
s = str(input())
a = [int(i) for i in s.split()]
for i in range(1, n):
    a[i] += a[i - 1]
k = int(input())
for i in range(k):
    l, r = map(int, input().split())
    if l - 1 == 0:
        s = a[r - 1]
    else:
        s = a[r - 1] - a[l - 2]
    print(s // 10)
