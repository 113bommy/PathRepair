n, x = map(int, input().split())
a = [int(s) for s in input().split()]
b = False
m = 3
d = {}
t = {}
for i in range(n):
    if a[i] in d.keys():
        print(0)
        b = True
        break
    else:
        d[a[i]] = 1
if b == False:
    for el in a:
        if el & x != el and el & x in d.keys():
            print(1)
            b = True
            break
    else:
        for el in a:
            if el & x not in t.keys():
                t[el & x] = 1
            else:
                print(2)
                b = True
                break
if b == False:
    print(-1)