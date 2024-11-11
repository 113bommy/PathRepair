import sys, itertools
f = sys.stdin

def take2(iterable):
    i = iter(iterable)
    while True:
        yield next(i), next(i)

n = int(f.readline())
adj =[[(v, c) for v, c in take2(map(int, f.readline().split()[2:]))] for _ in range(n)]
d = [100000 * 100 + 1] * n

d[0] = 0
queue ={0}
while len(queue):
    parent = queue.pop()
    for v, c in adj[parent]:
        if d[v] > d[parent] + c:
            d[v] = d[parent] + c
            queue.update([v])

for i in range(n):
    print(i, d[i])