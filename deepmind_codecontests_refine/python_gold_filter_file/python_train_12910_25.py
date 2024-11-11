n, k = map(int, input().split())
l = list(int(input()) for i in range(n))

left = max(l)-1; right = sum(l)

while left+1 < right:  #最大値と合計値の間のどこかに考えるべき値が存在する
    mid = (left + right) // 2
    cnt = 1; cur = 0  #初期化
    for a in l:
        if mid < cur + a:
            cur = a
            cnt += 1
        else:
            cur += a

    if cnt <= k:
        right = mid
    else:
        left = mid

print(right)
