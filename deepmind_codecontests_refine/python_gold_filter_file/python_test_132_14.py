t = int(input())

for _ in range(t):
    A = list(map(int, input().split()))
    out = []
    out.extend(A[:2])
    if A[2] < sum(out) or sum(out) < A[2]:
        out.append(A[2])
    else:
        out.append(A[3])


    print(*out)