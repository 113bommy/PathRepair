t = int(input())
for i in range(t):
    a, b = map(int, (input().split()))
    c = a-b
    if a == b:
        out = 0
    elif c % 2 == 1 and a < b:
        out = 1
    elif c % 2 == 0 and a < b:
        out = 2
    elif c%2 == 1 and a > b:
        out = 2
    else:
        out = 1
    print(out)
