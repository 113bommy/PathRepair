t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    if x == 1 and y != 1:
        print("NO")
    elif x <= 3 and y > 3:
        print("NO")
    else:
        print("YES")
