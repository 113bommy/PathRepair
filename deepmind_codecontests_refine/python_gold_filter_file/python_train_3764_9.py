a = []
A, b, c, d = map(int, input().split())
a.append(A)
a.append(b)
a.append(c)
a.append(d)
a.sort()
# print(a)
print(int(a[3]) - int(a[1]), int(a[3]) - int(a[2]), int(a[3]) - int(a[0]))