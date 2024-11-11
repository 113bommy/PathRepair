
n = int(input())
a = list(map(int, input().split(' ')))
a.sort()
mini = 100000000000
for i in range(len(a)):
    for j in range(i+1, len(a)):
        lmin = 0
        x = 0
        y = 1
        while y < (len(a)):
            if x == i or x == j:
                x += 1
                continue
            if y == i or y == j or y == x:
                y += 1
                continue
            lmin += abs(a[x] - a[y])
            x += 2; y += 2

        mini = min(lmin,mini)


print(mini)