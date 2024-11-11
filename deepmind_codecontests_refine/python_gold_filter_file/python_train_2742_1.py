def sides(plst):
    slst = [0, 0, 0]
    for i in range(3):
        s_2 = (plst[(i+1)%3][0] - plst[i][0]) ** 2 + (plst[(i+1)%3][1] - plst[i][1]) ** 2
        slst[i] = s_2
    slst.sort()
    if slst[0] + slst[1] == slst[2]:
        return True
    else:
        return False

coordinates = list(map(int, input().strip().split()))
p1 = [coordinates[0], coordinates[1]]
p2 = [coordinates[2], coordinates[3]]
p3 = [coordinates[4], coordinates[5]]
lst = [p1, p2, p3]
s = ''
if sides(lst):
    s = "RIGHT"
else:
    for i in range(3):
        point = lst[i]
        points = [[point[0]+1, point[1]], [point[0]-1, point[1]], [point[0], point[1]+1], [point[0], point[1]-1]]
        for x in points:
            if sides([x, lst[(i+1)%3], lst[(i+2)%3]]) and x not in [lst[(i+1)%3], lst[(i+2)%3]]:
                s = "ALMOST"
                #print([x, lst[(i+1)%3], lst[(i+2)%3]])
                break
        if s:
            break
if not s:
    s = "NEITHER"
print(s)