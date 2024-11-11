n = int(input())
l = list(map(int, input().split(" ")))
tf, ff, hh = 0, 0, 0
f = 1
for i in range(len(l)):

    if l[i] == 25:
        tf += 1
    elif l[i] == 50:
        if tf > 0:
            tf -= 1
            ff += 1
        else:
            print("NO")
            f = 0
            break
    elif l[i] == 100:
        if tf >= 1 and ff >= 1:
            tf -= 1
            ff -= 1
            hh += 1
        elif tf >= 3:
            tf -= 3
            hh += 1
        else:
            print("NO")
            f = 0
            break
if f == 1:
    print("YES")

    # -----------------------------------------------------------------------------------------!
