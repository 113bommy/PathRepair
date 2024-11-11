N, M = (map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

C = 1
A.sort(reverse=True)
B.sort(reverse=True)

aloop = 0
bloop = 0

if len(set(A)) != len(A) or len(set(B)) != len(B):
    C = 0

else:
    for k in range(N * M, 0, -1):
        if aloop < N and bloop < M and k == A[aloop] and k == B[bloop]:
            aloop += 1
            bloop += 1
        elif aloop < N and k == A[aloop]:
            C *= bloop
            aloop += 1
        elif bloop < M and k == B[bloop]:
            C *= aloop
            bloop += 1
        else:
            C *= (aloop * bloop - (N * M - k))

        C = C % (10**9+7)
print(C)
