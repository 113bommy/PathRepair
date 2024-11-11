N,K = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))
A.sort()
F.sort()
suma = sum(A)
u = 10**12
d = 0
for i in range(50):
    x = (u + d)//2
    s = 0
    for i in range(N):
        f = F[i]
        j = -(i+1)
        a = A[j]
        b = x // f
        s += max(0,a-b)
    if s <= K:
        u = x
    else:
        d = x
print(u)