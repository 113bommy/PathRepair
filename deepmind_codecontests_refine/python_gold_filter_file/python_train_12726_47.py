a= int(input())
for _ in range(a):
    y,x = map(int, input().split())
    if y == 1:
        print(0)
    elif y == 2:
        print(x)
    else:
        print(2*x)