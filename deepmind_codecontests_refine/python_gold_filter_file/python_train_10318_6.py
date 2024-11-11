n = int(input())
v = list(map(int, input().split()))
f = [0 for x in range(1, 105)]
for x in v:
    f[x] = f[x] + 1
d = {}
next = 0
for i in range(1, 101):
    if f[i] == 1:
        if next == 0:
            d[i] = 0
        else:
            d[i] = 1
        next = next ^ 1
    elif f[i] == 2:
        d[i] = 1

if next == 1:
    for i in range(1, 101):
        if f[i] >= 3:
            d[i] = 2
            next = next ^ 1
            break
    if next != 0:
        print("NO")
        exit(0)

for i in range(1, 101):
    if i not in d:
        d[i] = 0

print("YES")
sol = []
for x in v:
    if d[x] == 0:
        sol.append('A')
    elif d[x] == 1:
        sol.append('B')
    else:
        sol.append('B')
        d[x] = 0

print(''.join(sol))



