n = int(input())
groups = 1
magnets = []
for _ in range(n):
    magnets.append(input())

for m in range(n - 1):
    if magnets[m][-1] == magnets[m + 1][0]:
        groups += 1

print(groups)