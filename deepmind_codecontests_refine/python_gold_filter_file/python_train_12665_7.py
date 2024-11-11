n, k = input().split()
n, k = int(n), int(k)
data = []
for _ in range(n):
    data.append(input())

size_x = len(data[0])
counter = [[0 for _ in range(size_x)] for _ in range(n)]

for i in range(n):
    for j in range(size_x):
        if data[i][j] == '#':
            continue
        vert, hor = True, True
        if j + k > size_x:
            hor = False
        if i + k > n:
            vert = False
        for e in range(1, k):
            if vert:
                if (data[i + e][j] == '#'):
                    vert = False
            if hor:
                if (data[i][j + e] == '#'):
                    hor = False
            if not vert and not hor:
                break
        if vert:
            for e in range(0, k):
                counter[i + e][j] += 1
        if hor:
            for e in range(0, k):
                counter[i][j + e] += 1

max_i = 0
max_j = 0
max_ = 0
for i in range(n):
    for j in range(size_x):
        if counter[i][j] > max_:
            max_i, max_j = i, j
            max_ = counter[i][j]
print(max_i + 1, ' ', max_j + 1)