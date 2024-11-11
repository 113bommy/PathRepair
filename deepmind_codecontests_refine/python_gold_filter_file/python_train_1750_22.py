# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

H,W,N=map(int,input().split())

sr,sc=map(int,input().split())
S=input()[:-1]
T=input()[:-1]

left=0
right=W+1
up=0
down=H+1

ans="YES"
for i,(s,t) in enumerate(zip(reversed(S),reversed(T))):
    if i!=0:
        if t=='R':
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

    if right-left==1 or down-up==1:
        ans="NO"
        break

if not left<sc<right or not up<sr<down:
    ans="NO"
print(ans)
