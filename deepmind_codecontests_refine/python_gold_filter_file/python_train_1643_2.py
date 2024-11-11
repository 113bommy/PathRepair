n, X = open(0).read().split()
n = int(n)
x = int(X, 2)
X = list(map(int, X))

def popcount(n):
    return bin(n).count('1')

ma = 2 * 10**5 + 1
dp = [0] * ma
for i in range(1, ma):
    dp[i] = dp[i % popcount(i)] + 1

c = popcount(x)
a = x % (c+1)
if c == 1:
    for i in range(n):
        if X[i]:
            print(0)
        else:
            print(dp[(a + pow(2, n-i-1, c+1)) % (c+1)] + 1)
else:
    b = x % (c-1)
    for i in range(n):
        if X[i]:
            print(dp[(b - pow(2, n-i-1, c-1)) % (c-1)] + 1)
        else:
            print(dp[(a + pow(2, n-i-1, c+1)) % (c+1)] + 1)