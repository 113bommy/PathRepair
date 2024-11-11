n, m = map(int, input().split())

arr = []
for _ in range(m):
    a, b = map(int, input().split())
    arr.append([a, b])

x = []
y1 = None
y2 = None
y = None


temp1 = arr[0]

x.append(temp1[0])
x.append(temp1[1])


ans = []
flag = True
# print(x)

for i in x:
    temp = 1
    index = []
    flag = True
    y = None
    y1 = None
    y2 = None
    for j, k in arr:

        if i != j and i != k:

            if y == None:
                y1 = j
                y2 = k
                y = j
                index = [j, k]

            else:
                if y != j and y != k and temp > 0:

                    y = y2
                    l = arr.index(index)
                    r = arr.index([j, k])
                    for p in range(l, r + 1):
                        temp1 = arr[p]

                        if y != temp1[0] and y != temp1[1] and i != temp1[0] and temp1[1]:
                            flag = False
                    temp -= 1
                elif temp <= 0:
                    if y!= j and y != k:
                        flag = False
        # print(flag)
        # print(i, y, j, k)
    # print(flag)
    ans.append(flag)
    if flag:
        break
'''
5 6
1 2
2 3
1 4
5 1
2 5
3 2
'''
# print(ans)

if any([x for x in ans]) or flag:

    print("YES")
else:
    print("NO")
