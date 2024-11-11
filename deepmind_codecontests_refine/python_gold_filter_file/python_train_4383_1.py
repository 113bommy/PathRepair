n = int(input())
a = [int(i) for i in input().split()]
a.sort()
c = 0
i = 0
j = 1
while j < n:
    if a[i] != a[j]:
        c += 1
        i += 1
        j += 1
    else:
        j += 1
print(c)