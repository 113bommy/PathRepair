def f(n):
    ans = 1
    for i in range(1, n + 1):
        ans = ans * i
    return ans
def C(n, m):
    return int(f(n) / (f(n - m) * f(m)))
n = int(input()) 
print(C(n, 5) + C(n, 6) + C(n, 7))
