k2, k3, k5, k6 = map(int, input().split())
n256 = min(k2, k5, k6)
k2 -= n256
n32 = min(k3, k2)
print(256 * n256 + 32 * n32)
