import sys
input = sys.stdin.readline
N = int(input())
x = list(map(int, input().split()))
mod = 10 ** 9 + 7

class Factorial:
  def __init__(self, n, mod):
    self.f = [1]
    for i in range(1, n + 1):
      self.f.append(self.f[-1] * i % mod)
    self.i = [pow(self.f[-1], mod - 2, mod)]
    for i in range(1, n + 1)[: : -1]:
      self.i.append(self.i[-1] * i % mod)
    self.i.reverse()
  def factorial(self, i):
    return self.f[i]
  def ifactorial(self, i):
    return self.i[i]
  def combi(self, n, k):
    return self.f[n] * self.i[n - k] % mod * self.i[k] % mod

f = Factorial(N, mod)
res = 0
t = [0] * (N + 1)
for i in range(N):
  t[i + 1] = t[i] * (i + 1) + f.factorial(i) % mod
  t[i + 1] %= mod
#print(t)
for i in range(N - 2, -1, -1):
  res += (x[i + 1] - x[i]) * t[i + 1] * f.factorial(N - 1) % mod * f.ifactorial(i + 1) % mod
  res %= mod
print(res)