n = int(input())
# if n <= 11:
#     print(1)
# else:
l, r = 0, int(1e18) + 1
k = -1
while l < r - 1:
    sm = 0
    cur = n
    k = (l + r) // 2
    while cur > 0:
        c = min(cur, k)
        sm += c
        cur -= c
        cur -= cur // 10
    if 2 * sm >= n:
        r = k
    else:
        l = k
print(r)
