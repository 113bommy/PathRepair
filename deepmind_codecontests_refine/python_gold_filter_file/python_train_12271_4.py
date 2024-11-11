n = int(input())
for i in range(n):
    x, y, z =map(int, input().split())
    if x*x + y*y == z*z or y*y + z*z == x*x or x*x + z*z == y*y :
        print("YES")
    else:
        print("NO")

