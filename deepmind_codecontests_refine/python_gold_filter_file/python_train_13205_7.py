def combinations(n, r):
    res = 1
    for i in range(n - r + 1, n + 1):
        res *= i
    for i in range(2, r + 1):
        res //= i
    return res

N, A, B = map(int,input().split())
v = list(map(int,input().split()))

v.sort(reverse=True)
ans1 = sum(v[0:A]) / A

num1 = v[0:A].count(v[A - 1])
num2 = v[A:N].count(v[A - 1])

ans2 = 0
if v[0] == v[A]:
    for i in range(A, N):
        if v[i] == v[A]:
            idx = i + 1
    for i in range(A, min(B, idx) + 1):
        ans2 += combinations(num1 + num2, i)
else:
    ans2 = combinations(num1 + num2, num1)

print(ans1)
print(ans2)