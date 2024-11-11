import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

mod = 10 ** 9 + 7

N = int(input())
vec = [[] for _ in range(N)]
for _ in range(N-1) :
  A, B = map(int, input().split())
  vec[A-1].append(B-1)
  vec[B-1].append(A-1)

sub_size = [[] for _ in range(N)]

def dfs(cur=0, pre=-1) :
  s = 0
  for nex in vec[cur] :
    if nex == pre :
      continue
    t = dfs(nex, cur)
    s += t
    sub_size[cur].append(t)
  if s != N - 1 :
    sub_size[cur].append(N - 1 - s)

  return s + 1

dfs()

power = [1]
for _ in range(N) :
  power.append(power[-1]*2%mod)

ret = 0
for i in range(N) :
  tmp = power[N-1]-1
  for ss in sub_size[i] :
    tmp -= power[ss]-1
  ret += tmp

ret = ret*pow(power[N], mod - 2, mod)% mod

print(ret)