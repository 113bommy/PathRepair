n = int(input())
x = 0
y = 0
a = 0
b = 0
negetive = -1
for i in range(0,n):
    x, y, a, b = map(int,input().split())
    total_distant = a + b
    d = abs(x - y)
    t = d /total_distant
    if t % 2 > 0 and t % 2 < 1:
        print(negetive)

    elif t % 2 > 1 and t % 2 < 2:
        print(negetive)
    else:
        print(int(t))