def solve():
    line = input()
    n = int(line.split(' ')[0])
    i = 0
    s = []
    a = []
    b = []
    c = []
    while i < n:
        line = input()
        s.append(int (line.split(' ')[0]))
        a.append(int (line.split(' ')[1]))
        b.append(int (line.split(' ')[2]))
        c.append(int (line.split(' ')[3]))
        i += 1
    i = 0
    while i < n:
        sum = int((s[i] // c[i]) + ((s[i] // c[i]) // a[i]) * b[i])
        print(sum)
        i += 1
solve()
