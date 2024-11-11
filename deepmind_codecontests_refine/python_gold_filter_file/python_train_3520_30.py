N = int(input())
As = list(map(int, input().split()))
o = [0]*(N**2)
INF = 10**19
from itertools import accumulate
aa = [0] + list(accumulate(As))

for i in range(1, N+1):
    for j in range(N-i+1):
        span = (i-1)*N+j
        # 長さi, 開始位置jの合成コスト+構成要素の和
        if i == 1:
            o[span] = As[j]
            continue
        C = INF
        for k in range(1, i):
            # 長さ,開始位置=(k,j)と(i-k,j+k)
            span1, span2 = (k-1)*N+j, (i-k-1)*N+j+k
            C = min(C, o[span1]+o[span2])
        o[span] = C + aa[(j+i-1)+1] - aa[(j-1)+1]
print(o[span]-aa[-1])