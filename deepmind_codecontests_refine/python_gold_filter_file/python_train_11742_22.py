import sys
input = sys.stdin.readline

def main():
  n = int(input())
  T = [[] for _ in range(n)]
  D = {}
  for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    T[a].append(b)
    T[b].append(a)
    D[(a, b)] = 1<<i
    D[(b, a)] = 1<<i
  m = int(input())

  def dfs(u, v):
    parent = [-1]*n
    seen = [False]*n
    stack = [u]
    seen[u] = True
    while stack:
      nv = stack[-1]
      if nv == v:
        return stack
      for i in T[nv]:
        if seen[i]:
          continue
        stack.append(i)
        seen[i] = True
        break
      else:
        stack.pop()

  def popcount(n):
    c = (n & 0x5555555555555555) + ((n>>1) & 0x5555555555555555)
    c = (c & 0x3333333333333333) + ((c>>2) & 0x3333333333333333)
    c = (c & 0x0f0f0f0f0f0f0f0f) + ((c>>4) & 0x0f0f0f0f0f0f0f0f)
    c = (c & 0x00ff00ff00ff00ff) + ((c>>8) & 0x00ff00ff00ff00ff)
    c = (c & 0x0000ffff0000ffff) + ((c>>16) & 0x0000ffff0000ffff)
    c = (c & 0x00000000ffffffff) + ((c>>32) & 0x00000000ffffffff)
    return c
              
  E = [0]*m
  for i in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    edge = dfs(u, v)
    for j in range(len(edge)-1):
      E[i] |= D[(edge[j], edge[j+1])]

  ans = 0
  for i in range(2**m):
    s = 0
    for j in range(m):
      if i>>j & 1:
        s |= E[j]
    cnt = popcount(i) % 2
    ans += (-1)**cnt * 2**(n-1-popcount(s))
  print(ans)
  
if __name__ == "__main__":
  main()