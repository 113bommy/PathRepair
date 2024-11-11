a = list(map(int, input().split()))
a = [[a[2*i], a[2*i+1]] for i in range(4)]

b = list(map(int, input().split()))
b = [[b[2*i], b[2*i+1]] for i in range(4)]

def int_p(p1, p2, p3, p4):
    b1, a1, c1 = p1[1] - p2[1], p2[0]-p1[0], p2[0]*p1[1]-p1[0]*p2[1]
    b2, a2, c2 = p3[1] - p4[1], p4[0]-p3[0], p4[0]*p3[1]-p3[0]*p4[1]

    x = (a2*c1-a1*c2) / (a2*b1-a1*b2)
    y = (b2*c1-b1*c2) / (a1*b2-a2*b1)
    return (x, y)

for i in range(4):
    p1, p2 = a[i], a[i+1 if i < 3 else 0]
    for j in range(4):
        p3, p4 = b[j], b[j+1 if j < 3 else 0]

        x,y = int_p(p1, p2, p3, p4)
        if p1[0] == p2[0]:
            if x <= max(p3[0], p4[0]) and x >= min(p3[0], p4[0]) and y <= max(p1[1], p2[1]) and y >= min(p1[1], p2[1]):
                print('YES')
                exit(0)
        else:
            if y <= max(p3[1], p4[1]) and y >= min(p3[1], p4[1]) and x <= max(p1[0], p2[0]) and x >= min(p1[0], p2[0]):
                print('YES')
                exit(0)

ax, bx = [x for x, y in a], [x for x, y in b]
ay, by = [y for x, y in a], [y for x, y in b]

bx.sort()
by.sort()
a1, a2, a3, a4 = [min(ax), min(ay)], [max(ax), min(ay)], [max(ax), max(ay)], [min(ax), max(ay)]
b1, b2, b3, b4 = [bx[0], by[1]], [bx[1], by[0]], [bx[-1], by[1]], [bx[1], by[-1]]

def get_y_at(p1, p2, x):
    y = p1[1] + (p1[1] - p2[1]) / (p1[0] - p2[0]) * (x - p1[0])
    return y

def get_x_at(p1, p2, y):
    x = p1[0] + (p1[0] - p2[0]) / (p1[1] - p2[1]) * (y - p1[1])
    return x

if b2[1] > a1[1] and b4[1] < a3[1] and b1[0] > a1[0] and b3[0] < a2[0]:
    print('YES')
elif a1[1] > get_y_at(b1, b2, a1[0]) and a2[1] > get_y_at(b2, b3, a2[0]) and a3[1] < get_y_at(b3, b4, a3[0]) and a4[1] < get_y_at(b4, b1, a4[0]):
    print('YES')
else:
    print('NO')