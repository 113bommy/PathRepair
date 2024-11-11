from math import sqrt


def ro(x, y):
    return sqrt((x[0] - y[0])**2 + (x[1] - y[1])**2)


a, b, c = list(map(int, input().split()))
A = [0, 0]
B = [0, 0]
A[0], A[1], B[0], B[1] = list(map(int, input().split()))
if a == 0 or b == 0:
    #print(1)
    print(float(abs(A[0] - B[0]) + abs(A[1] - B[1])))
elif ((-a*A[0] - c) / b > max(A[1], B[1]) and (-a*B[0] - c) / b > max(A[1], B[1])) or ((-a*A[0] - c) / b < min(A[1], B[1]) and (-a*B[0] - c) / b < min(A[1], B[1])):
    #print(2)
    print(float(abs(A[0] - B[0]) + abs(A[1] - B[1])))
elif ((B[0] - A[0]) / (B[1] - A[1])) * (-a / b) <= 0:
    #print(3)
    print(float(abs(A[0] - B[0]) + abs(A[1] - B[1])))
else:
    ab = False
    bb = False
    cb = False
    db = False
    C = [0, 0]
    D = [0, 0]
    if min(A[1], B[1]) <= (-a*min(A[0], B[0]) - c) / b <= max(A[1], B[1]):
        ab = True
    if min(A[1], B[1]) <= (-a*max(A[0], B[0]) - c) / b <= max(A[1], B[1]):
        cb = True
    if min(A[0], B[0]) < (-b*max(A[1], B[1]) - c) / a < max(A[0], B[0]):
        bb = True
    if min(A[0], B[0]) < (-b*min(A[1], B[1]) - c) / a < max(A[0], B[0]):
        db = True
    k = -a/b
    r = abs(A[0] - B[0]) + abs(A[1] - B[1])
    if ab and bb:
        C[0] = min(A[0], B[0])
        C[1] = (-a*min(A[0], B[0]) - c) / b
        D[0] = (-b*max(A[1], B[1]) - c) / a
        D[1] = max(A[1], B[1])
        r = abs(C[1] - min(A[1], B[1])) + abs(max(A[0], B[0]) - D[0]) + ro(C, D)
    if ab and cb:
        C[0] = min(A[0], B[0])
        C[1] = (-a*min(A[0], B[0]) - c) / b
        D[0] = max(A[0], B[0])
        D[1] = (-a*max(A[0], B[0]) - c) / b
        if C[1] < D[1]:
            r = abs(C[1] - min(A[1], B[1])) + abs(max(A[1], B[1]) - D[1]) + ro(C, D)
        else:
            r = abs(D[1] - min(A[1], B[1])) + abs(max(A[1], B[1]) - C[1]) + ro(C, D)
    if ab and db:
        C[0] = min(A[0], B[0])
        C[1] = (-a*min(A[0], B[0]) - c) / b
        D[0] = (-b*min(A[1], B[1]) - c) / a
        D[1] = min(A[1], B[1])
        r = abs(max(A[1], B[1]) - C[1]) + abs(max(A[0], B[0]) - D[0]) + ro(C, D)
    if bb and cb:
        C[0] = (-b * max(A[1], B[1]) - c) / a
        C[1] = max(A[1], B[1])
        D[0] = max(A[0], B[0])
        D[1] = (-a * max(A[0], B[0]) - c) / b
        r = abs(C[0] - min(A[0], B[0])) + abs(D[1] - min(A[1], B[1])) + ro(C, D)
    if bb and db:
        C[0] = (-b * max(A[1], B[1]) - c) / a
        C[1] = max(A[1], B[1])
        D[0] = (-b * min(A[1], B[1]) - c) / a
        D[1] = min(A[1], B[1])
        if C[0] > D[0]:
            r = abs(D[0] - min(A[0], B[0])) + abs(max(A[0], B[0]) - C[0]) + ro(C, D)
        else:
            r = abs(C[0] - min(A[0], B[0])) + abs(max(A[0], B[0]) - D[0]) + ro(C, D)
    if cb and db:
        C[0] = max(A[0], B[0])
        C[1] = (-a * max(A[0], B[0]) - c) / b
        D[0] = (-b * min(A[1], B[1]) - c) / a
        D[1] = min(A[1], B[1])
        r = abs(D[0] - min(A[0], B[0])) + abs(max(A[1], B[1]) - C[1]) + ro(C, D)
    print(r)
