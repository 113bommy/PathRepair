from math import ceil

n, m = map(int, input().split())
visited = [-1 for i in range(m+1)]
visited[0] = 0
for tim in range(1, n+1):
    t, x, y = map(int, input().split())
    if(t == 1):
        x = ceil(x/100000)
        for i in range(m, -1, -1):
            # print(i)
            k = i
            if(visited[k] == -1):
                continue
            for j in range(y):
                k += x
                if(k > m or visited[k] != -1):
                    break
                else:
                    visited[k] = tim
    else:
        #x = (x/100000)
        for i in range(m, -1, -1):
            k = i
            if(visited[k] == -1):
                continue
            for j in range(y):
                k = ceil(k*x/100000)
                if(k > m or visited[k] != -1):
                    break
                else:
                    visited[k] = tim
for i in range(1, m+1):
    print(visited[i], end=' ')
print()
