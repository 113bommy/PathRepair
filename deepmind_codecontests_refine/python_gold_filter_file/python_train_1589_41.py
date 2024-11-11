t = int(input())
for _ in range(t):
    x, y, n = map(int, input().split())
    print(x*((n-y)//x) + y)
