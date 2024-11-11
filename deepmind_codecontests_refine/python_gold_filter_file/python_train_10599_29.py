n, k = map(int, input().split())
mod = 10**9+7
A = [list(map(int, input().split())) for _ in range(n)]

# A*B
def mul(a, b):
    c = [[0]*len(b[0]) for i in range(len(a))]
    for i in range(len(a)):
        for k in range(len(b)):
            for j in range(len(b[0])):
                c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod

    return c

#A**n
def pow(a, n):
    b = [[0]*len(a) for i in range(len(a))]
    for i in range(len(a)):
        b[i][i] = 1
    while n > 0:
        if n & 1 == 1:
            b = mul(a, b)
        a = mul(a, a)
        n = n>>1
    return b

B = pow(A, k)
#print(B)
ans = 0
for i in range(n):
    ans += sum(B[i])
    ans %= mod
print(ans)