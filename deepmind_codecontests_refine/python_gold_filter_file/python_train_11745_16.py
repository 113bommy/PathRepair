N, X = map(int, input().split())
def f(n, x):
    if x ==0:
        return 0
    if n == 0:
        return 1
    if x <= 2**(n+1) - 2:
        return f(n-1, x-1)
    else:
        return 2**n+f(n-1, x-2**(n+1)+1)
print(f(N, X))