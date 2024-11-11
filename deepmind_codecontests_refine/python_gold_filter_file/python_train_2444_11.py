
n, m = [int(x) for x in input().split()]
matrix = []
colors = set()
for i in range(n):
    line = list(input().strip())
    colors.update(set(line))
    matrix.append(line)

colors = list(colors)
marked = [x.lower() for x in colors]
directions = [(1,0),(0,1),(-1,0),(0,-1)]

stack = []
actual = (matrix[0][0],matrix[0][0].lower())
before = (n+1,m+1)
for k in range(n):
    for l in range(m):
        if matrix[k][l] in colors:
            actual = (matrix[k][l],matrix[k][l].lower())
            stack.append([(k,l),before])
            matrix[k][l] = actual[1]

        while not(stack == []):
            (i,j),parent = stack.pop()
            if matrix[i][j] == actual[1]:
                for d in directions:
                    idy = i+d[0]
                    idx = j+d[1]
                    if (idy >= 0) and (idy < n) and (idx >= 0) and (idx < m):
                        if (matrix[idy][idx] == actual[1]) and (idy != parent[0] or idx != parent[1]):
                            print("Yes")
                            quit()
                        if matrix[idy][idx] == actual[0]:
                            matrix[idy][idx] = actual[1]
                            stack.append([(idy,idx),(i,j)])    
print("No")