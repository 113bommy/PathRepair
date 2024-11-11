n, k = [int(f) for f in input().split(' ') if f]
blocks = (n + 2) // 3
if k == 0:
    print(0, 0)
    exit()
if blocks > k:
    print([0, 1][k+1 <= n], 2*k)
else:
    spaces = 2 * blocks
    leftToArrange = max(0, k - blocks - (n - blocks * 3))
    print([0, 1][k+1 <= n], max([0, 1][k+1 <= n], spaces - leftToArrange))
