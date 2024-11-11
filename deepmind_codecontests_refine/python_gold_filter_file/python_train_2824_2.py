n, k = map(int, input().split())
line = [int(x) for x in input().split(' ')]
line.append(line[-1])
maxs = []

last = line[0]
count = 1
for i in range(1, n+1):
    if line[i] != last:
        count += 1
    else:
        maxs.append(count)
        count = 1
    last = line[i]

if maxs == []:
    print (1)
else:
    print (max(maxs))
