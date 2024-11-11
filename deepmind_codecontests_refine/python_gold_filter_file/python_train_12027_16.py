def f (k, n):
    ans = 1
    i = max(k - n, n) + 1;
    while (i <= k):
        ans *= i
        i += 1
    i = 2
    while (i <= min(k - n, n)):
        ans //= i
        i += 1
    return ans

n = int(input())
print(f(n, 5) * n * (n - 1) * (n - 2) * (n - 3) * (n - 4))
