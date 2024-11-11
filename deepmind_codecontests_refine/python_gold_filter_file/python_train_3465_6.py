d = int(input())
for i in range (d):
    a, b = map(int, input().split())
    c = input().strip("0")
    e = 0
    f = 0
    g = 0
    for j in range (len(c)):
        if c[j] == "1":
            if g:
                if g >= a:
                    g = 0
                    f += a
                    e = 0
                else:
                    f += g
                    g = 0
            e = 1
        else:
            g += b
    print(f + a * e)