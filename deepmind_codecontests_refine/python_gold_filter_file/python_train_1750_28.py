# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

H,W,N=map(int,input().split())

sr,sc=map(int,input().split())
S=input()[:-1]
T=input()[:-1]

#gridのindexは入力値のまま扱う(grid=[1,1]~[H,W])
#left<x<rightの間が生存範囲(初めはグリッド全てが生存可能状態)
left=0
right=W+1
up=0
down=H+1

ans="YES"
#手を逆順で見ていく。
for s,t in zip(reversed(S),reversed(T)):
    if t=='R':#生存可能範囲を広げる(0より小さくならないようにする)
        left=max(0,left-1)
    elif t=="L":
        right=min(W+1,right+1)
    elif t=="D":
        up = max(0,up-1)
    else:
        down=min(H+1,down+1)


    if s=="R":
        right-=1
    elif s=="L":
        left+=1
    elif s=="D":
        down-=1
    else:
        up+=1

    #もし、途中でright-left==1。つまり、生存可能範囲がなくなってしまったら、
    #落とされてしまうため、ans=NOにして終了する
    if right-left==1 or down-up==1:
        ans="NO"
        break

#全ての手を見た後で、スタート地点が生存可能範囲に入っていればOK
if not left<sc<right or not up<sr<down:
    ans="NO"
print(ans)
