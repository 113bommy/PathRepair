l = int(input())

line = input()

if l % 2 == 0:
    index = l // 2
    m = float("inf")

    while index < l - 1 and line[index] == '0':
        index += 1

    if line[index] != '0':
        f = int(line[0:index])
        s = int(line[index:])
        m = min(m, f + s)

    index = l // 2 + 1

    while index >= 1 and line[index] == '0':
        index -= 1

    if line[index] != '0':
        f = int(line[0:index])
        s = int(line[index:])
        m = min(m, f + s)

    print(m)


else:
    index = l // 2 + 1
    m = float("inf")
    while index < l - 1 and line[index] == '0':
        index += 1

    if line[index] != '0':
        f = int(line[0:index])
        s = int(line[index:])
        m = min(m, f + s)

    index = l // 2 + 1

    while index >= 1 and line[index] == '0':
        index -= 1

    if line[index] != '0':
        f = int(line[0:index])
        s = int(line[index:])
        m = min(m, f + s)



    index = l // 2
    q = float("inf")
    while index < l - 1 and line[index] == '0':
        index += 1

    if line[index] != '0':
        f = int(line[0:index])
        s = int(line[index:])
        q = min(q, f + s)

    index = l // 2 + 1

    while index >= 1 and line[index] == '0':
        index -= 1

    if line[index] != '0':
        f = int(line[0:index])
        s = int(line[index:])
        q = min(q, f + s)

    print(min(q, m))
