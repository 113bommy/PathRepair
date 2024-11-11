n = int(input())
a = []
b = 1
for i in range(n):
    a.append(int(input()))
for i in range(1,n):
    if a[i-1] != a[i]:
        b += 1
print(b)
