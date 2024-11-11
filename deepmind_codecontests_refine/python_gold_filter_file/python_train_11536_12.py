
"""
無理な場合を考えてみよう
→全体の辺の本数が奇数なら絶対無理

それ以外は？
説1:辺が偶数なら絶対作れる説

辺を選択し、そのどちらか片方にのみ xor1する
→すべての辺の数字を0にできるか？？(初期値は0)
なんかできそう

辺の向きを変えることで1を伝播させることが出来る
→同じ点にぶつけられる！！
ので、偶数本なら絶対できる


どうやって構成する？
適当に置く→1の点を適当に2つ選び、パス上にある辺を全部反転させる
確かにできるけど…遅くね？

もっと簡単にできないか？
適当に木を取る→深い方から整合性を合わせていけば終わり(最終的には根に収束するので)
各点に関して動かすのは高々1辺だけだから、木を取った辺のみ考えて反転させる
(それ以外は適当に置いておく)

dfsで終わり→解けた！！！
"""
import sys
sys.setrecursionlimit(200000)
N,M = map(int,input().split())

lisN = [ [] for i in range(N) ]
xorlis = [0] * N
AB = []

if M % 2 == 1:
    print (-1)
    sys.exit()

for i in range(M):

    a,b = map(int,input().split())
    AB.append([a,b])
    a -= 1
    b -= 1

    lisN[a].append([b,i])
    lisN[b].append([a,i])
    xorlis[b] ^= 1

visited = [False] * N
def dfs(now):

    visited[now] = True

    for nex,eind in lisN[now]:
        if visited[nex]:
            continue
        cat = dfs(nex)
        if cat != 0:
            xorlis[nex] ^= 1
            xorlis[now] ^= 1
            t = AB[eind][1]
            AB[eind][1] = AB[eind][0]
            AB[eind][0] = t

    return xorlis[now]

dfs(0)
#print (xorlis)
if 1 in xorlis:
    print (-1)
    sys.exit()

else:
    for i,j in AB:
        print (j,i)