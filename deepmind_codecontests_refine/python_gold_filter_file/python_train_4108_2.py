a = int(input())
b = list(map(int, input().split()))
c = [0] * 100015
for i in range (a):
    c[b[i]] += b[i]
d = 0
e = 0
f = 0
i = 1
g = 0
while i < 100005:
    if not g:
        e += c[i]
        f += c[i + 1]
        if e >= f:
            d += e
            e = 0
            f = 0
            i += 2
        else:
            e += c[i + 2]
            if f >= e:
                d += f
                e = 0
                f = 0
                i += 3
                g = 0
            else:
                f += c[i + 3]
                if e >= f:
                    d += e
                    e = 0
                    f = 0
                    g = 0
                else:
                    g = 1
                i += 4
    else:
        e += c[i]
        if f >= e:
            d += f
            e = 0
            f = 0
            i += 1
            g = 0
        else:
            f += c[i + 1]
            if e >= f:
                d += e
                e = 0
                f = 0
                g = 0
            else:
                g = 1
            i += 2
            
print(d + max(e, f))