a = [None] * 4

a[0] = input()
a[1] = input()
a[2] = input()
a[3] = input()

b = [None] * 4

for i in range(4):
    b[i] = a[0][i] + a[1][i] + a[2][i] + a[3][i]

c = [a[0][2] + a[1][1] + a[2][0], a[0][3] + a[1][2] + a[2][1] + a[3][0], a[1][3] + a[2][2] + a[3][1], a[0][1] + a[1][2] + a[2][3]]
d = [a[0][0] + a[1][1] + a[2][2] + a[3][3], a[1][0] + a[2][1] + a[3][2], 'a', 'b']


f = True

for j in range(4):
        if a[j].count(".xx") or a[j].count("xx.") or a[j].count("x.x") != 0:
            print("YES")
            f = False
            break
        elif b[j].count(".xx") or b[j].count("xx.") or b[j].count("x.x")!= 0:
            print("YES")
            f = False
            break
        elif c[j].count(".xx") or c[j].count("xx.") or c[j].count("x.x") != 0:
            print("YES")
            f = False
            break
        elif d[j].count(".xx") or d[j].count("xx.") or d[j].count("x.x") != 0:
            print("YES")
            f = False
            break
if f:
    print("NO")
