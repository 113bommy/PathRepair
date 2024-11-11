n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

def insertionsort(a, n, g):
    global c
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j = j - g
            c += 1
        a[j + g] = v

c = 0
g = [1]
while g[-1] * 3 + 1 < n:
    g.append(g[-1] * 3 + 1)
g.reverse()
for i in range(len(g)):
    insertionsort(a, n, g[i])
print(len(g))
print(" ".join(map(str, g)))
print(c)
for i in range(n):
    print(a[i])
