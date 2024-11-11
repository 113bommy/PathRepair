S = input()

L = 0
U = len(S)

while U - L > 1:
    M = (U + L) // 2

    OK = False
    for i in range(2):
        A = i
        B = M
        if A % 2 != B % 2: B -= 1

        NG = False
        for s in S:
            if s == '0':
                A -= 1
                B -= 1
            elif s == '1':
                A += 1
                B += 1
            else:
                A -= 1
                B += 1

            if A < 0: A += 2
            if B > M: B -= 2
            if A > B:
                NG = True
                break

        if not NG:
            OK = True
            break

    if OK:
        U = M
    else:
        L = M

print(U)
