###template###
import sys
def input(): return sys.stdin.readline().rstrip()
def mi(): return map(int, input().split())
###template###

N = int(input())

#neighbor
#0~N-1でアクセス
ngb = [[] for _ in range(N)]

#入力
#すべて-1ベースに
for _ in range(N-1):
  a,b = mi()
  a -= 1
  b -= 1
  ngb[a].append(b)
  ngb[b].append(a)

start = 0
goal = N-1

#nodes[番号][0]には探索済みならstartからの距離、未探索なら-1を格納
#nodes[番号][1]には（探索済みなら）「何番のノードから来たか(0~N-1)」を格納
nodes = [[-1, -1] for _ in range(N)]

#nodesにスタート地点を入れ、stackを初期化
nodes[start][0] = 0
nodes[start][1] = -1
stack = []
for eachngb in ngb[start]:
  stack.append(eachngb)
  nodes[eachngb][0] = 1
  nodes[eachngb][1] = start

#phase1 start->goalの最短距離を探索
while 1:
  try:
    nownode = stack.pop()
  except:
    break

  if nownode == goal:
    break

  #現在のノードとエッジで繋がるノードのうち、未探索のものをスタックに入れる
  #スタックに入れたらもう探索済みとする
  #木なので、ngb[]が空になっていることはありえない
  for eachngb in ngb[nownode]:
    if nodes[eachngb][0] == -1:
      stack.append(eachngb)
      #距離を+1して入れ、今のノード番号（どこから来たか、となる）を入れる
      nodes[eachngb][0] = nodes[nownode][0]+1
      nodes[eachngb][1] = nownode

#phase2 B, Wの根を見つける
length = nodes[goal][0] #スタートからゴールへの距離
FenRootPos = length // 2 #Fenの根がある距離
SnRootPos = FenRootPos + 1 #Snukeの根がある距離
FenRoot = -1 #Fenの根ノード番号
SnRoot = -1 #Snukeの根ノード番号

#ゴールからフェネックの根がある場所まで、順に逆走していく
nextnode = goal
#このループ内において、iは今見ているノードのスタートからの距離を表す
for i in range(length, FenRootPos-1, -1):
  nownode = nextnode
  if i == SnRootPos:
    SnRoot = nownode
  elif i == FenRootPos:
    FenRoot = nownode
  nextnode = nodes[nownode][1]

#phase3 B, Wそれぞれの根から、その木のノード数を数える
#お互いの根は探索済み(0)とすることで、重複を避ける

#まずはFen
#探索済みかどうか
ndsFen = [-1] * N
ndsFen[SnRoot] = 0
ndsFen[FenRoot] = 0
stkFen = []
stkFen.append(FenRoot)
FenCnt = 0
while 1:
  try:
    nownode = stkFen.pop()
  except:
    break

  #現在のノードとエッジで繋がるノードのうち、未探索のものをスタックに入れる
  #スタックに入れたらもう探索済みとする
  #木なので、ngb[]が空になっていることはありえない
  for eachngb in ngb[nownode]:
    if ndsFen[eachngb] == -1:
      stkFen.append(eachngb)
      #今回は距離は関係無いので、0を入れるだけでいい
      ndsFen[eachngb] = 1
      FenCnt += 1

#次はSnuke
#探索済みかどうか
ndsSn = [-1] * N
ndsSn[FenRoot] = 0
ndsSn[SnRoot] = 0
stkSn = []
stkSn.append(SnRoot)
SnCnt = 0
while 1:
  try:
    nownode = stkSn.pop()
  except:
    break

  #現在のノードとエッジで繋がるノードのうち、未探索のものをスタックに入れる
  #スタックに入れたらもう探索済みとする
  #木なので、ngb[]が空になっていることはありえない
  for eachngb in ngb[nownode]:
    if ndsSn[eachngb] == -1:
      stkSn.append(eachngb)
      #今回は距離は関係無いので、0を入れるだけでいい
      ndsSn[eachngb] = 1
      SnCnt += 1

print('Fennec' if FenCnt > SnCnt else 'Snuke')

