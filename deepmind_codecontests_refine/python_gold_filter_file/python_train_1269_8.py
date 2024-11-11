MOD = int(1e9) + 7
N, M = map(int, input().split())
fib = [0 for i in range(max(N, M)+1)]
fib[0] = 1
fib[1] = 1
for i in range(2, max(N, M) + 1):
    fib[i] = (fib[i-1] + fib[i-2]) % MOD
print((2 * (fib[N] + fib[M] - 1)) % MOD)