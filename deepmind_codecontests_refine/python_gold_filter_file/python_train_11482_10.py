for _ in range(int(input())):
    input()

    sp = {}
    for i, v in enumerate(map(int, input().split()), 1):
        sp.setdefault(v, []).append(i)

    if len(sp) == 1:
        print('NO')
        continue

    sp = sorted(sp.values(), key=lambda x: len(x))

    print('YES')
    temp = len(sp[0]) - 1
    for v in sp[1:]:
        for v1 in v:
            print(sp[0][0], v1)
            if temp > 0:
                print(sp[0][temp], v1)
                temp -= 1
