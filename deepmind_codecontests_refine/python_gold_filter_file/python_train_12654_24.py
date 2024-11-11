n = int(input())
a = []
s = 0
zero_i = None
zero_j = None
zero_in_1 = True
for i in range(n):
    a.append(list(map(int, input().split())))
    for j in range(n):
        if a[i][j] == 0:
            zero_i = i
            zero_j = j
if n == 1:
    print(1)
    exit(0)

zero_s = sum(a[zero_i])

for i in range(len(a)):
    if i != zero_i:
        s = sum(a[i])
        break

zero_value = s - zero_s
if zero_value <= 0:
    print(-1)
    exit(0)
a[zero_i][zero_j] = zero_value

for i in range(n):
    if sum(a[i]) != s:
        print(-1)
        exit(0)

for j in range(n):
    column_s = 0
    for i in range(n):
        column_s += a[i][j]
    if column_s != s:
        print(-1)
        exit(0)

d1_s = 0
for i in range(n):
    d1_s += a[i][i]
if d1_s != s:
    print(-1)
    exit(0)
d2_s = 0
for i in range(n):
    d2_s += a[i][n - i - 1]
if d2_s != s:
    print(-1)
    exit(0)
print(zero_value)
