import sys
input = lambda: sys.stdin.readline().rstrip()
n = int(input())
xy = []
for _ in range(n):
    x, y = map(int, input().split())
    xy.append((x, y))
if n%2:
    print('NO')
    exit(0)
for i in range(n//2):
    xy0 = xy[i]
    xy1 = xy[i+1]
    xy2 = xy[n//2+i]
    xy3 = xy[(n//2+i+1)%n]
    if xy3[0]-xy2[0]!=xy0[0]-xy1[0]:
        print('NO')
        exit(0)
    if xy3[1]-xy2[1]!=xy0[1]-xy1[1]:
        print('NO')
        exit(0)
print('YES')