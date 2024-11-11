import sys
input = sys.stdin.readline
from collections import defaultdict

N,M = map(int,input().split())
d_to_LR = defaultdict(list)
for _ in range(N):
    L,R = map(int,input().split())
    d_to_LR[R-L+1].append((L,R))

def BIT_update(tree,x,value):
    while x <= M:
        tree[x] += value
        x += x & (-x)

def BIT_sum(tree,x):
    s = 0
    while x:
        s += tree[x]
        x -= x & (-x)
    return s

tree = [0] * (M+1) # BIT で管理。左にあるLの個数 - (R+1)の個数 → いくつの[L,R]に入っているか
long = N # 長すぎて自動回収できる
answer = [0] * (M+1)

for m in range(1,M+1):
    for L,R in d_to_LR[m]:
        BIT_update(tree,L,1)
        BIT_update(tree,R+1,-1)
        long -= 1
    answer[m] = sum(BIT_sum(tree,x) for x in range(m,M+1,m)) + long

print('\n'.join(map(str, answer[1:])))