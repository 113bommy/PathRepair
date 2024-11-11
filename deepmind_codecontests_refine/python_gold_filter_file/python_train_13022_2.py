n, m = map(int, input().split())

l = []
lst = []
for i in range(1, m + 1):
    l.append(i)

for i in range(n):
    a, b = map(int, input().split())
    for j in range(a, b + 1):
        if j in l:
            number = l.index(j)
            l[number] -= j

for value in l:
    if value > 0:
        lst.append(value)
print(len(lst))
print(*lst)