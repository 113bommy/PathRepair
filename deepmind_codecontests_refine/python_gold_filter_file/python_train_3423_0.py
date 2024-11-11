ld, rd = [0, 0, 0, 0], [0, 0, 0, 0]
while True:
    try:
        l, r = map(float, input().split())
        if l < 0.2:
            ld[3] += 1
        elif l < 0.6:
            ld[2] += 1
        elif l < 1.1:
            ld[1] += 1
        else:
            ld[0] += 1

        if r < 0.2:
            rd[3] += 1
        elif r < 0.6:
            rd[2] += 1
        elif r < 1.1:
            rd[1] += 1
        else:
            rd[0] += 1

    except:
        break

for l, r in zip(ld, rd):
    print(l, r)