N = int(input())
*A, = map(int, input().split())
*B, = map(int, input().split())
B.reverse()

ac = [0]*(N+1)
bc = [0]*(N+1)

ok = True
for i in range(N):
    ac[A[i]] += 1
    bc[B[i]] += 1

for i in range(1, N+1):
    if (ac[i]+bc[i]) > N:
        ok = False
        break

if ok:
    l, r = 0, N-1
    for i in range(N):
        if A[i] == B[i]:
            if A[i] != B[l] and A[l] != B[i]:
                B[l], B[i] = B[i], B[l]
                l += 1
            elif A[i] != B[r] and A[r] != B[i]:
                B[r], B[i] = B[i], B[r]
                r -= 1
    print("Yes")
    print(*B)
else:
    print("No")
