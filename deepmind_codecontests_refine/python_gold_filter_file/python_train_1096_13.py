n = int(input())

elements = list(map(int, input().split()))

if len(elements) != n:
    raise ValueError("wrong element number")

indices = []

for i, element in enumerate(elements):
    if element in (1, n):
        indices.append(i)

print(indices[1] - indices[0] + max(indices[0], n - 1 - indices[1]))
