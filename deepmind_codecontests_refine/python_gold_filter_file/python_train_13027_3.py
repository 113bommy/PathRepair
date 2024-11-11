ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

n = ii()
l = li()

d = {}

for i in range(len(l)):
    if l[i] in d:
        d[l[i]].append(i+1)
    else:
        d[l[i]] = [i+1]

c = 0
xi, yi = [1, 1]

for i in range(1, len(d)+1):
    xi1, yi1 = d[i]
    c += min(abs(xi - xi1)+abs(yi - yi1), abs(xi - yi1)+abs(yi - xi1))
    xi, yi = xi1, yi1

print(c)