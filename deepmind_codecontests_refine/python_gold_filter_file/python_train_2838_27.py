case = int(input())
for i in range(0, case):
    x, y, z = [int(x) for x in input().split()]
    maxCount = 0
    maxVal = max(x, y, z)
    minVal = min(x, y, z)
    for j in [x, y, z]:
        if maxVal == j:
            maxCount += 1
    if (x == y or x == z or y == z) and maxCount == 2:
        print("YES")
        print(maxVal, minVal, minVal)
    elif maxCount > 2:
        print("YES")
        print(x, y, z)
    else:
        print("NO")