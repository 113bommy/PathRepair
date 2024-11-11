n = int(input())
f = sum([int(i) for i in input().split(' ')])

c = 0
if n == 1:
    if f % 2 == 0:
        print(2)
    else:
        print(3)
else:
    for i in range(1, 6):
        if (f+i) % (n+1) != 1:
            c += 1

    print(c)
