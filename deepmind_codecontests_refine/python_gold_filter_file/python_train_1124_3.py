sc = iter(open(0).read().split())

N = int(next(sc))
Q = int(next(sc))

S = "_" + next(sc) + "_"

TD = tuple(zip(sc, sc))

l, r = 0, N + 1
for t, d in reversed(TD):

    if t == S[l + 1] and d == "L":
        l += 1
    elif t == S[l] and d == "R":
        l -= 1

    if t == S[r - 1] and d == "R":
        r -= 1
    elif t == S[r] and d == "L":
        r += 1

print(max(0, r - l - 1))