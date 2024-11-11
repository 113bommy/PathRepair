import random


def get_int():
    return int(input())


def put_equal_on(pos, S, T, swaps):
    if S[pos] == T[pos]:
        return True

    if not S[pos] in S[pos + 1 :]:
        if not S[pos] in T[pos + 1 :]:
            return False
        pos2 = pos + 1 + T[pos + 1 :].index(S[pos])
        T[pos2], S[pos2] = S[pos2], T[pos2]
        swaps.append((pos2, pos2))

    pos2 = pos + 1 + S[pos + 1 :].index(S[pos])
    T[pos], S[pos2] = S[pos2], T[pos]
    swaps.append((pos2, pos))
    return True


def prog():
    N = get_int()
    S = list(input())
    T = list(input())

    swaps = []
    for i in range(N - 1):
        if not put_equal_on(i, S, T, swaps):
            break

    if S != T:
        print("No")
    else:
        print("Yes")
        print(len(swaps))
        for a, b in swaps:
            print(a + 1, b + 1)


q = get_int()
for _ in range(q):
    prog()
