n = int(input())
point = []
mark = [[-10000000000,-10000000000]]
c = 0
for i in range(n):
    a,b = map(int,input().split())
    point.append([a,b])
for i in range(n):
    a,b = point[i]
    left = [a-b,a]
    right = [a,a+b]
    temp =[]
    # print(i, i)
    if mark[i][1] < left[0]:
        temp = left[::]
    if len(temp) == 0:
        r = i+1
        if r<n:
            # print(i, r)
            if point[r][0] > right[1]:
                temp = right[::]
        else:
            temp = right[::]
    if len(temp) == 0:
        mark.append([a,a])
    else:
        c+=1
        mark.append(temp[::])
print(c)
# print(mark)

# print(point)