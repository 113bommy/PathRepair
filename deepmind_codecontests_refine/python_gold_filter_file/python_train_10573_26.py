k2, k3, k5, k6 = map(int, input().split())
n256 = min(k2, k5, k6)
n32 = min(k3, k2 - n256)
print(32 * n32 + 256 * n256)
