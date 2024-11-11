h = input().split()
h[0] = int(h[0]); h[1] = int(h[1])
u = input().split()
u[0] = int(u[0]); u[1] = int(u[1])
count = 0

n = int(input())

for i in range(n):
    p = input().split()
    p[0] = int(p[0]); p[1] = int(p[1]); p[2] = int(p[2])
    hp = h[0]*p[0]+h[1]*p[1]+p[2]
    up = u[0]*p[0]+u[1]*p[1]+p[2]
    if (hp > 0 and up < 0) or (hp < 0 and up > 0):
        count += 1
print(count)