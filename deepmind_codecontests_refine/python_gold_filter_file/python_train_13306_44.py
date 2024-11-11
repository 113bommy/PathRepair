import math

l = int(input())

n = int(math.log2(l)) + 1
g = []

for i in range(1, n):
    g.append([i, i + 1, 2**(n - i - 1)])
    g.append([i, i + 1, 0])
    
s = 2**(n - 1)

while l > s:
    t = n - int(math.log2(l - s))
    g.append([1, t, s])
    s += 2**int(math.log2(l - s))
    
print(n, len(g))
for i in range(0, len(g)):
    print(" ".join(list(map(str, g[i]))))