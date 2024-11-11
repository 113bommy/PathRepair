k2, k3, k5, k6 = map(int, input().split())
s = 0

if k6 >= k2 <= k5: s += 256 * k2
elif k2 >= k6 <= k5: s += 256 * k6; s += 32 * (k2 - k6) if k3 > k2 - k6 else 32 * k3
elif k2 >= k5 <= k6: s += 256 * k5; s += 32 * (k2 - k5) if k3 > k2 - k5 else 32 * k3

print(s)