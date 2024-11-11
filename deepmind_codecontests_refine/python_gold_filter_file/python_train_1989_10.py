n = int(input())
m = int(input())
a = []
s = 0
for i in range(n):
    a.append(int(input()))
k = max(a)
for i in range(n):
    s = s + k - a[i]
l = 0
if s > m:
    l = k
else:
    l = k + (m - s + n - 1) // n
print(l, k + m)