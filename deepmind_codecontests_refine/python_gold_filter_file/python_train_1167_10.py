t = int(input())
for i in range(t):
    n = int(input())
    path = []
    for j in range(n):
        a,b = map(int,input().split())
        path.append([a,b])
    path.sort()
    coor = [0,0]
    flag = 0
  #  print(path)
    p = ""
    for j in range(0,n):
        if coor[0] > path[j][0] or coor[1] > path[j][1]:
            flag = 1
            break
        p+=("R" * (path[j][0]-coor[0]))
        p+=("U" * ( path[j][1]-coor[1]))
        coor[0],coor[1] = path[j][0],path[j][1]
    if flag:
        print("NO")
    else:
        print("YES")
        print(p)
