def Warshall_Floyd(edges,N):
  """頂点N個のグラフ上の隣接行列edges(空欄はinfとせよ)が与えられたとき, 
  2点間の最短距離距離を隣接行列で返す"""
  for k, i, j in itertools.product(range(N), range(N),range(N)):
    if edges[i][j]>edges[i][k]+edges[k][j]: return 1
  return 0
 
import sys
import itertools
N=int(input())
A=[list(map(int,input().split())) for i in range(N)]
if Warshall_Floyd(A,N):
  print(-1)
  sys.exit()
 
ans=0
for i, j in itertools.product(range(N),range(N)):
  need=1
  for k in range(N):
    if k!=i and k!=j and A[i][j]==A[i][k]+A[k][j]:
      need=0
      break
  if need:ans+=A[i][j]
print(ans//2)