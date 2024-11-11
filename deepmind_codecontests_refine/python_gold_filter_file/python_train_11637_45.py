N = int(input())
*A, = map(int, input().split())
*B, = map(int, input().split())

ac = [0]*(N+1)
bc = [0]*(N+1)

ok = True
for i in range(N):
    ac[A[i]] += 1
    bc[B[i]] += 1

d = 0
for i in range(1, N+1):
    if (ac[i]+bc[i]) > N:
        ok = False
        break
    ac[i] += ac[i-1]
    bc[i] += bc[i-1]
    d = max(d, ac[i]-bc[i-1])

if ok:
    print("Yes")
    print(*[B[(i-d) % N] for i in range(N)])
else:
    print("No")
