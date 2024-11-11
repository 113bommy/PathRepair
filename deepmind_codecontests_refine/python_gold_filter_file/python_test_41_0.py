n, k = tuple(map(int, input().split()))
arr = [i for i in range(n)]

colors = [[0 for _ in range(n)] for _ in range(n)]

groups = []
group = []
for i in range(n):
    group.append(arr[i])
    if len(group) == k:
        groups.append(group[::])
        group = []
if group:
    groups.append(group[::])
    group = []

# print(groups)

color = 1
while True:
    for group in groups:
        for i in range(len(group)):
            for j in range(i + 1, len(group)):
                if colors[group[i]][group[j]] == 0:
                    colors[group[i]][group[j]] = color
    if len(groups) == 1:
        break
    group2 = []
    groups2 = []
    for group in groups:
        group2.append(group)
        if len(group2) == k:
            group3 = []
            for g in group2:
                for j in g:
                    group3.append(j)
            groups2.append(group3[::])
            group2 = []
    if group2:
        group3 = []
        for g in group2:
            for j in g:
                group3.append(j)
        groups2.append(group3[::])
        group2 = []
    groups = groups2[::]
    color += 1
    # print(groups)

# print(colors)

print(color)
for i in range(n):
    for j in range(i + 1, n):
        print(colors[i][j], end=' ')
print()


