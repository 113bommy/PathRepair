l, r, a = map(int, input().split())

if a >= abs(l - r):
    print((max(l, r) + (a - abs(l - r)) // 2) * 2)

else:
    print((min(l, r) + min(abs(l - r), a)) * 2)
