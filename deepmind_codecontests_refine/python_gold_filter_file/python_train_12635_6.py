n, k = map(int, input().split())

arr = list(map(int, input().split()))

pos = list()
neg = list()

hasZero = False

for v in arr:
    if v > 0:
        pos.append(v)
    else:
        neg.append(v)

    if v == 0:
        hasZero = True

neg.sort()
pos.sort()

for idx, v in enumerate(neg):
    if k > 0:
        neg[idx] *= -1
        k -= 1
    else:
        break

if k & 1 == 1 and not hasZero:
    if len(neg) > 0 and len(pos) > 0:
        if neg[-1] <= pos[0]:
            neg[-1] *= -1
        else:
            pos[0] *= -1
    elif len(neg) > 0:
        neg[-1] *= -1
    else:
        pos[0] *= -1

print(sum(neg + pos))
