
parent = {}
size = {}
cells = {}


def make_set(v):
    parent[v] = v
    size[v] = 1
    cells[v] = [v]

def find_set(v):
    if v == parent[v]:
        return v
    parent[v] = find_set(parent[v])
    return parent[v]

def union_sets(a, b):
    a = find_set(a)
    b = find_set(b)
    if a != b:
        if size[a] < size[b]:
            a, b = b, a
        parent[b] = a
        size[a] += size[b]
        cells[a] += cells[b]


n = input()
n = int(n)
for i in range(0, n):
    make_set(i + 1)

for i in range(0, n-1):
    a, b = input().split()
    union_sets(int(a), int(b))

for i in cells[find_set(1)]:
    print(i, end=' ')
print(" ")
# print(cells[parent[1]])
