n = int(input())

sets = []

for i in sorted(list(map(int, input().split()))):
    sets.append([i - 1, i + 1])

min_count = 0

i = 0
while i < len(sets):
    t = i
    i += 1
    while i < len(sets) and sets[t][1] >= sets[i][0]:
        i += 1
    min_count += 1

max_count = 0

i = 0
prev = -1
while i < len(sets):
    if prev < sets[i][0]:
        max_count += 1
        prev = sets[i][0]
    elif prev == sets[i][0]:
        max_count += 1
        prev = sets[i][0] + 1
    elif prev == sets[i][0] + 1:
        max_count += 1
        prev = sets[i][0] + 2
    i += 1


print(min_count, max_count)
