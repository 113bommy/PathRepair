r, c = map(int, input().split())
arr = []
for i in range(r):
    arr.append(list(map(int, input().split())))

for line in arr:
    line.append(sum(line))
    
arr.append([sum([line[i] for line in arr]) for i in range(c  + 1)])

for line in arr:
    print(*line)