n = int(input())
a = list(map(int,input().split()))

x = a[-1]
i = -1

for j in range(len(a)-1):
    if a[j] <= x:
        i += 1
        a[i], a[j] = a[j], a[i]

a[i + 1], a[n - 1] = "[" + str(a[n - 1]) + "]", a[i + 1]

print(*a)