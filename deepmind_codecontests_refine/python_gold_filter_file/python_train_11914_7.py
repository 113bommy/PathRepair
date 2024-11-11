n = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
for i in range(1, n[0] + 1):
    if i in a:
        c.append(1)
    else:
        c.append(2)
print(*c)

# UBCF
# CodeForcesian
# ♥
# پریسا
