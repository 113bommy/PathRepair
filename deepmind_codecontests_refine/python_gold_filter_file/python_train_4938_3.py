import sys

n, v = list(map(int, sys.stdin.readline().rstrip().split()))
kc_ls = []
kayaks = []
catamaran = []
total_space = 0
total_capacity = 0
for i in range(1, n + 1):
    kc_ls.append(
        tuple(map(int, sys.stdin.readline().rstrip().split() + [i]))
    )  # Numbering the items
kc_ls.sort(key=lambda x: x[1] if x[0] == 1 else x[1] / 2)


while v - total_space > 1 and len(kc_ls) > 0:
    t, p, num = kc_ls.pop()
    total_space += t
    total_capacity += p
    if t == 1:
        kayaks.append((t, p, num))
    else:
        catamaran.append((t, p, num))

if len(kc_ls) > 0:
    if v - total_space == 1:
        tc, pc, numc = kc_ls.pop()
        if tc == 1:
            kayaks.append((tc, pc, numc))
            total_space += tc
            total_capacity += pc

        elif len(kayaks) > 0:
            tk, pk, numk = kayaks[-1]

            tk1 = 2
            while tk1 != 1 and len(kc_ls) > 0:
                tk1, pk1, numk1 = kc_ls.pop()

            if tk1 == 1:
                if pk + pk1 < pc:
                    kayaks.pop()
                    catamaran.append((tc, pc, numc))
                    total_capacity += pc - pk
                    total_space += tc - tk
                else:
                    kayaks.append((tk1, pk1, numk1))
                    total_space += tk1
                    total_capacity += pk1
            else:
                if pk < pc:
                    kayaks.pop()
                    catamaran.append((tc, pc, numc))
                    total_capacity += pc - pk
                    total_space += tc - tk


kayaks.extend(catamaran)

print(total_capacity)
if len(kayaks) > 0:
    print(" ".join([str(i[2]) for i in kayaks]))
else:
    print()
