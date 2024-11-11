s = input()
t = input()

if(len(s) != len(t)):
    print(-1)
    exit()

dist = [[10**15 for j in range(26)] for i in range(26)]

for i in range(26):
    dist[i][i] = 0

n = int(input())
for i in range(n):
    a = input().split()
    x = ord(a[0]) - 97
    y = ord(a[1]) - 97
    w = int(a[-1])

    dist[x][y] = min(dist[x][y], w)

for k in range(26):
    for i in range(26):
        for j in range(26):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

ans = ''
res = 0

n = len(s)

for i in range(n):
    if(s[i] == t[i]):
        ans += s[i]
        continue
    
    cost = 10**15
    pos = -1

    x = ord(s[i]) - 97
    y = ord(t[i]) - 97

    for j in range(26):
        if(dist[x][j] + dist[y][j] < cost):
            cost = dist[x][j] + dist[y][j]
            pos = j

    if(pos == -1):
        print(-1)
        exit()
    
    res += cost
    ans += chr(pos + 97)

print(res)
print(ans)