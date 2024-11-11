import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

def main():
  MOD = 10**9+7
  n = int(input())
  T = [[] for _ in range(n)]
  for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    T[a].append(b)
    T[b].append(a)
  C = [[] for _ in range(n)]
  seen = [False]*n
  dp = [0]*n
  def dfs(v):
    cnt = 1
    seen[v] = True
    for nv in T[v]:
      if seen[nv]:
        continue
      C[v].append(nv)
      cnt += dfs(nv)
    dp[v] = cnt
    return cnt

  dfs(0)

  p = [1]*(n+1)
  inv = [1]*(n+1)
  inv_two = pow(2, MOD-2, MOD)
  for i in range(n):
    p[i+1] = p[i] * 2 % MOD
    inv[i+1] = inv[i] * inv_two % MOD
  ans = 0
  for i in range(n):
    s = 1
    t = 1
    cnt = 1
    for c in C[i]:
      l = dp[c]
      s *= inv[l]
      s %= MOD
      t += p[l] - 1
      t %= MOD
      cnt += l
    r = n - cnt
    s *= inv[r]
    s %= MOD
    t += p[r] - 1
    t %= MOD
    res = (1 - s*t) % MOD * inv_two
    res %= MOD
    ans += res
    ans %= MOD
  print(ans)

if __name__ == "__main__":
  main()