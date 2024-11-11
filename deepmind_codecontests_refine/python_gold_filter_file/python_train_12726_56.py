a = int(input())
for _ in range(a):
    x,y = map(int, input().split())
    if x == 1:
        print(0)
    elif x == 2:
        print(y)
    else:
        print(2*y)
