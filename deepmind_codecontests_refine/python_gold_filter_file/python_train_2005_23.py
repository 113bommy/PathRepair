def op(p, c):
    pref = c[:p].copy()
    for i in range(p-1, -1, -1):
        c[i] = (pref[p-i-1] + 1) % 2
   #print(c, ":", p)


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, list(input())))
    b = list(map(int, list(input())))
    array = []
    for i in range(n-1, -1, -1):
        if a[i] != b[i]:
            if b[i] == a[0]:
                array.append(1)
                op(1, a)
            array.append(i+1)
            op(i+1, a)
    #print(a)
    print(len(array), *array)