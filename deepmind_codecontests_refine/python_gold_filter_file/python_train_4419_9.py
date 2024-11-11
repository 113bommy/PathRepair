n = int(input())
x = []
for i in range(n):
    c, p = map(int, input().split())
    x += [(p, c, i)]

k = int(input())
r = list(map(int, input().split()))
sm = 0
ans = []
x.sort(reverse=True)

for i in range(n):
    count = x[i][0]
    cost = x[i][1]
    uk = x[i][2]
    tm1 = -1
    tm2 = 100000
    for j in range(k):
        if cost <= r[j] < tm2:
            tm1 = j
            tm2 = r[j]
    if tm1> -1:
        r[tm1] = 0
        ans += [(uk, tm1)]
        sm += count
print(len(ans), sm)

for (i, j) in ans:
    print(i + 1, j + 1)
