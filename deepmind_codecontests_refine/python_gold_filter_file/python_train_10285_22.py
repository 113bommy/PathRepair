import sys
sys.setrecursionlimit(500000)
input = sys.stdin.readline
N = int(input()); MOD=pow(10,9)+7
G = [[] for _ in range(N)]
for i in range(N-1):
  a,b = map(int,input().split())
  a-=1;b-=1
  G[a].append(b);G[b].append(a)
#print(G)
ans = 0

def dfs(v,p): #自分と親
  global ans #ansをGlobal変数として宣言
  res = 1 #戻り値。vを含めた部分木のサイズ。自分の分で最初は1
  ts = [] #vから生えている部分木のリスト
  for u in G[v]:
    if u == p:
      continue
    t = dfs(u,v) #uの部分木のサイズが戻り値
    res += t
    ts.append(t)
  if p != -1: #根以外なら親側の部分木が存在する。
    ts.append(N-res)
  now = pow(2,N-1,MOD) - 1 #自分以外を決めるのが2^(N-1)通り。自分以外が全部0が1通り。
  for x in ts:
    now -= pow(2,x,MOD) - 1 #各部分木に一個以上黒がある場合の数。全通り - 全部白
  ans = (ans+now)%MOD
  return res #vを含めた部分木のサイズ

dfs(0,-1)
ALL = pow(2,N,MOD)
#print(ans,ALL)
ans = ans*pow(ALL,MOD-2,MOD)%MOD #フェルマーの小定理より1/ALL = ALL^(MOD-2)
print(ans)
           