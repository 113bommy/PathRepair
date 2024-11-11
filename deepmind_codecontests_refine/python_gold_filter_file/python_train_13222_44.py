import sys

def shellSort(data, cnt, g, n):
    for idx in range(g, n):
        j = idx - g
        v = data[idx]
        while j >= 0 and data[j] > v:
            data[j+g] = data[j]
            j -= g
            cnt += 1
        data[j+g] = v
    return data, cnt

n, gap = int(input()), []
a = ([int(i) for i in sys.stdin.readlines()], 0)
g = 0
while g <= n//9:
    g = 3 * g + 1
    gap.append(g)
m = len(gap)
for i in gap[::-1]:
    a = shellSort(a[0], a[1], i, n)
print(m)
print(" ".join(map(str, gap[::-1])))
print(a[1])
for i in range(n):
    print(a[0][i])

