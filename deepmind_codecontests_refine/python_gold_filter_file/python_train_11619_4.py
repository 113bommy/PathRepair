n, m = list(map(int, input().split()))
p = list(map(int, input().split()))
for _ in range(m):
    l, r, x = map(int, input().split())
    l -= 1
    r -= 1
    x -= 1
    a = 0
    t = p[x]
    for i in range(l, r + 1):
        a += p[i] < t
    if a == x - l: print("Yes")
    else: print("No")