n, k = map(int, input().split())
a = list(map(int, input().split()))
f = list(map(int, input().split()))
a.sort()
f.sort(reverse=True)

left, right = -1, a[-1] * f[0]

while right - left > 1:#2分探索で探す。
    mid = (left + right) // 2
    ck = 0#修行回数
    for i in range(n): 
      ck += max(0, a[i] - mid // f[i])# (a[i] - ck) * f[i] = midを解いて左記になる。
    if ck <= k: right = mid
    else: left = mid

print(right)
