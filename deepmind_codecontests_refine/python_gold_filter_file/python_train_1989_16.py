n = int(input())
a = []
m = int(input())
for i in range(n):
    a.append(int(input()))
maxx = max(a)
s = 0
for i in range(n):
    s += maxx - a[i]
minn = maxx + ((m - s) + n - 1) // n if m > s else maxx
print(minn, maxx + m)
