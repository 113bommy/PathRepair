n = int(input())
for i in range(n):
    x, y, a, b = map(int,input().split())
    if (y - x) % (a + b) != 0 :
        print("-1")
    else:
        print((y - x) // (a + b))