n = int(input())
x = list(map(int, input().split()))
d = []
for x1, x2 in zip(x, x[1:]):
    d.append(x2 - x1)
mod = 10 ** 9 + 7
base = 1

P = 10**9 + 7
N = n+2
inv_t = [0]+[1]
for i in range(2,N):
  inv_t += [inv_t[P % i] * (P - int(P / i)) % P]

for i in range(1, n):
    base *= i
    base %= mod
ans = 0
b = base
for i, di in enumerate(d):
    ans += (base * di)  % mod
    ans %= mod
    base += b * inv_t[i+2]
    base % mod
print(ans)
