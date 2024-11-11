from itertools import accumulate
n, k = map(int, input().split())
As = list(map(int, input().split()))

acc = [0]+list(accumulate(As))
mx = 0
sums = []
for i in range(n+1):
    for j in range(i+1,n+1):
        s = acc[j]-acc[i]
        sums.append(s)

# 計算
now = 0
for d in range(40,-1,-1):
    cnt = 0
    for s in sums:
        # 上から見て、bitが立っている数がk個以上かどうか
        # 最上位がkこ未満だったら、そのbitはもう使わない
        # 1000 -> 1100 -> 1100 -> 1101 みたいな絞り込み
        if s & (now|(1<<d)) == now|(1<<d):
            cnt += 1
    # print(d,cnt)
    if cnt >= k:
        now |= 1<<d
print(now)