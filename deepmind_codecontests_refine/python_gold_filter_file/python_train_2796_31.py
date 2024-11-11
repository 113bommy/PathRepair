N, x = map(int,input().split())
if x == 1 or x == 2*N-1:
    print("No")
    exit(0)
if N == 2:
    print("Yes")
    print(*[1,2,3], sep="\n")
    exit(0)

A = [0 for k in range(2*N-1)]
A[N-2], A[N-1], A[N] = x-1, x, x+1
t = 1
for k in range(N-2):
    while x-1 <= t <= x+1:
        t += 1
    A[k] = t
    t += 1
for k in range(N+1,2*N-1):
    while x-1 <= t <= x+1:
        t += 1
    A[k] = t
    t += 1
print("Yes")
print(*A, sep="\n")