k2, k3, k5, k6 = map(int, input().split())

max_, min_ = min(k5, k6, k2), 0
if max_ < k2:
    min_ = min(k2 - max_, k3)

print(max_ * 256 + min_ * 32)
