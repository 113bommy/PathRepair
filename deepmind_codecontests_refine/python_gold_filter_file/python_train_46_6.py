n = int(input())
a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
b = input().split()
for i in range(len(b)):
    b[i] = int(b[i])
c = input().split()
for i in range(len(c)):
    c[i] = int(c[i])
a = sorted(a)
b = sorted(b)
c = sorted(c)
i = 0
while (i <= len(b)-1) and (a[i] == b[i]):
    i += 1
print(a[i])
i = 0
while (i <= len(c)-1) and c[i] == b[i]:
    i += 1
print(b[i])
