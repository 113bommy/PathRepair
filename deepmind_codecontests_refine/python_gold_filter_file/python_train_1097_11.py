n = int(input())
x,y,z = 0,0,0
for i in range(n):
    l = list(map(int, input().strip().split()))
    x = x + l[0]
    y = y + l[1]
    z = z + l[2]
if (x == 0) and (y == 0) and (z == 0):
    print("YES")
else:
    print("NO")
