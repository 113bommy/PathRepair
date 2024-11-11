r, c = map(int, input().split())
graph = []
for i in range(r):
    a = input()
    d = []
    for b in range(len(a)):
        d.append(a[b])
    graph.append(d)
can = True
for i in range(r):
    for j in range(c):
        if graph[i][j] == "S":
            if i-1 >= 0:
                if graph[i-1][j] == "W":
                    can = False
                    break
                else:
                    if can and graph[i-1][j] == ".":
                        graph[i-1][j] = "D"
            if j-1 >= 0:
                if graph[i][j-1] == "W":
                    can = False
                    break
                else:
                    if can and graph[i][j-1] == ".":
                        graph[i][j-1] = "D"
            if i+1 < r:
                if graph[i+1][j] == "W":
                    can = False
                    break
                else:
                    if can and graph[i+1][j] == ".":
                        graph[i+1][j] = "D"
            if j+1 < c:
                if graph[i][j+1] == "W":
                    can = False
                    break
                else:
                    if can and graph[i][j+1] == ".":
                        graph[i][j+1] = "D"
if can:
    print("YES")
    for i in range(r):
        for j in range(c):
            print(graph[i][j],end="")
        print()
else:
    print("NO")