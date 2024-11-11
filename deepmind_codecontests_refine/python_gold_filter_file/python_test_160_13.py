t = int(input())

for _ in range(t):

    p = input()
    p = p.split()

    for i in range(len(p)):
        p[i] = int(p[i])

    a = p[4] - p[2]
    b = p[5] - p[3]

    if a == 0 or b == 0:
        print(0)

    elif a >= 0 and b >= 0:
        print(min(a,b))

    elif a >= 0 and b < 0:
        temp = 2*(p[1] - p[3]) + p[3] - p[5]
        print(min(a,temp))

    elif b >= 0 and a < 0:
        temp = 2*p[0] - p[2] - p[4]
        print(min(b, temp))

    else:
        temp = 2*(p[1] - p[3]) + p[3] - p[5]
        temp1 = 2*p[0] - p[2] - p[4]
        print(min(temp,temp1))