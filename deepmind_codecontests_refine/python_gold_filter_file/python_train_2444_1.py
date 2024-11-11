n, m = map(int, input().split())

colors = []

for i in range(n):
    input_colors = input()
    colors.append([])

    for color in input_colors:
        colors[i].append(color)


for i in range(n):
    for j in range(m):

        next_j = j + 1

        while(next_j < m):
            if colors[i][j] != colors[i][next_j]:
                break
            
            next_i = i + 1

            while(next_i < n):
                if colors[next_i][next_j] != colors[i][j]:
                    break
                
                res = True

                for k in range(j, next_j + 1, 1):
                    if colors[next_i][k] != colors[i][j]:
                        res = False
                
                if res:
                    print('Yes')
                    exit()
                
                next_i += 1
            next_j += 1


print('No')