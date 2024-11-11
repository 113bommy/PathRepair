#Starting python by CA method

n, l =(int(x) for x in input().split())
positions = [int(x) for x in input().split()]
positions.sort()
dst = [0]
for i in range(1, len(positions)):
    dst.append(positions[i] - positions[i-1])
print(max(max(dst) / 2, l - max(positions), min(positions)))