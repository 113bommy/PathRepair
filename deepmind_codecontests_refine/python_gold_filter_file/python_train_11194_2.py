n, a, b = map(int, input().split())
rev, akt = False, 0

if n > a * b:
    print(-1)
else:
    pole = [str(i + 1) for i in range(n)]

    for i in range(a):
        akt2 = akt + b
        if akt2 > n:
            akt2 = n

        odpoved = pole[akt:akt2]

        if len(odpoved) < b:
            odpoved += [str(0) for j in range(b - len(odpoved))]

        if rev:
            print(' '.join(reversed(odpoved)))
        else:
            print(' '.join(odpoved))

        rev = not rev
        akt += b
