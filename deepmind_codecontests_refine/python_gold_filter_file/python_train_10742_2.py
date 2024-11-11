n = int(input())
coords = n*[-1]
for i in range(n):
    coords[i] = [int(i) for i in input().split()] + [i]
coords.sort()
i = 0
while i < len(coords) - 1:
    if coords[i][:2] == coords[i + 1][:2]:
        print(coords[i][3] + 1, coords[i + 1][3] + 1)
        coords.pop(i)
        coords.pop(i)
        i -= 1
    i += 1
i = 0
while i < len(coords) - 1:
    if coords[i][:1] == coords[i + 1][:1]:
        print(coords[i][3] + 1, coords[i + 1][3] + 1)
        coords.pop(i)
        coords.pop(i)
        i -= 1
    i += 1
while len(coords) > 0:
    print(coords.pop()[3] + 1, coords.pop()[3] + 1)
