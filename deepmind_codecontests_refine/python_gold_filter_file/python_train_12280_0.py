while 1:
    n = int(input())
    if n == 0:break
    m = []
    f = 1
    for _ in range(n):
        _, a, _, v, b = input().split()
        v = int(v[3:])
        x, y = -1, -1
        for i in range(len(m)):
            if a in m[i]:x = i
            if b in m[i]:y = i
        if x >= 0:
            if y >= 0:
                if x == y:
                    if m[x][a] - v != m[x][b]:f = 0
                else:
                    for i in m[y]:
                        m[x][i] = m[y][i] + m[x][a] - m[y][b] - v
                    m.pop(y)
            else:
                m[x][b] = m[x][a] - v
        elif y >= 0:
            m[y][a] = m[y][b] + v
        else:
            m.append({a:v, b:0})
    print("Yes" if f else "No")
