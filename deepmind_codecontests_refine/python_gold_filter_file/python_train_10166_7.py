import math

p, y = map(int, input().split())

if y % 2 == 0:
    y -= 1
for i in range(y, p, -2):
    ok = True
    ans = i
    for d in range(3, int(math.sqrt(i)) + 1):
        if i % d == 0:
            if d <= p:
                ok = False
            break
    if ok:
        print(ans)
        exit()
print(-1)
