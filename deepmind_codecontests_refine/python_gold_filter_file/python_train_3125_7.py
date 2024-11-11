n = int(input())
a = [int(x) for x in input().split()]

c = 0

for i in range(n):
    for j in range(1, n):
        if a[j - 1] > a[j]:
            tmp = a[j - 1]
            a[j - 1] = a[j]
            a[j] = tmp
            c += 1

print(" ".join([str(x) for x in a]))
print(c)