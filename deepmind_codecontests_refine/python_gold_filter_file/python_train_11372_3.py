u,v = map(int, input().split())

def xorcise(u, v):
    if u > v or (v&1 != u&1):
        print(-1)
        return

    m = v.bit_length()
    r_bits = list(map(int, reversed(format(v-u, "b").zfill(m))))

    x = u
    y = 0
    z = 0

    for b in range(m-1):
        d = 1 << b

        if r_bits[b+1]:
            if x&d:
                y += d
                z += d
            else:
                x += d
                y += d

    out = []
    if x: out.append(x)
    if y: out.append(y)
    if z: out.append(z)
    print(len(out))
    if out: print(*out)

xorcise(u, v)
