t = int(input())
for i in range(t):
    n = int(input())
    x = []
    y = []
    for i in range(n):
        a, b = map(int, input().split())
        x.append(a)
        y.append(b)
    if n == 1:
        print(0)
    elif min(y) > max(x):
        print(0)
    else:
        print(abs(max(x)-min(y)))
