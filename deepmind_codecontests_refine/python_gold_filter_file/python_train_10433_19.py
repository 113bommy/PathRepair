x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

node = [[x0, y0]]
for i in range(70):
    xi = node[i][0] * ax + bx
    yi = node[i][1] * ay + by
    node.append([xi, yi])
    if xi >= 10**20 or yi >= 10**20:
        break


ans = 0
for i in range(len(node)+1):
    for j in range(i, len(node)):
        new = node[i:j+1]
        flag = 0
        for k in range(len(new)): #k:startnode
            time = t
            time -= abs(xs-new[k][0]) + abs(ys-new[k][1])
            nx, ny = new[k][0], new[k][1]
            for l in range(k-1, -1, -1):
                time -= abs(nx-new[l][0]) + abs(ny-new[l][1])
                nx, ny = new[l]
                if time < 0:
                    break
            for l in range(k+1, len(new)):
                time -= abs(nx-new[l][0]) + abs(ny-new[l][1])
                nx, ny = new[l]
                if time < 0:
                    break
            if time < 0:
                continue
            else:
                ans = max(ans, len(new))
                flag = 1
                break
        if flag == 1:
            continue


print(ans)
