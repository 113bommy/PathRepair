n, k = map(int, input().split())
status = []
cnt = []
for i in range(n):
    status += [list(input())]
    cnt += [[0 for i in range(n)]]
for i in range(n):
    for g in range(n - k + 1):
        flag = 1
        for j in range(g, g + k):
            if status[i][j] == "#":
                flag = 0
                break
        if flag == 1:
            for j in range(g, g + k):
                cnt[i][j] += 1
for i in range(n):
    for g in range(n - k + 1):
        flag = 1
        for j in range(g, g + k):
            if status[j][i] == "#":
                flag = 0
                break
        if flag == 1:
            for j in range(g, g + k):
                cnt[j][i] += 1
x = y = 1
m_till = 0
for i in range(n):
    for j in range(n):
        if cnt[i][j] > m_till:
            m_till = cnt[i][j]
            x = i + 1
            y = j + 1
print(x, y)