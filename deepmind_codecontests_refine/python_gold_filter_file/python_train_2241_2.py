a, b, c, d,n = [int(x) for x in input().split()]
p = [int(x) for x in input().split()]

grid = [['o' for _ in range(a+c)] for _ in range(max(b,d))]

e, f = 0,0
dr = 1
if b > d:
    for i in range(d,b):
        for j in range(a,a+c):
            grid[i][j] = '.'
    if d%2 == 1:
        e, f = 0, (a+c-1)
        dr = -1
elif d > b:
    for i in range(b,d):
        for j in range(0,a):
            grid[i][j] = '.'
    if b%2 == 0:
        e, f = 0, (a+c-1)
        dr = -1
k = 0
for _ in range((a+c)*max(d,b)):
    if grid[e][f] != '.':
        grid[e][f] = chr(ord('a')+k)
        p[k] -= 1
        if p[k] == 0: k+=1
    f += dr
    if f == -1:
        e, f = e+1, 0
        dr = 1
    if f == a+c:
        e, f = e+1, a+c-1
        dr = -1

print("YES")
for i in range(max(b,d)):
    print("".join(grid[i]))