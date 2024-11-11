def ceil(a, b):
    return (a + b - 1) // b

def allBlocks(lim=10**18):
    blocks = []
    i = 0
    res = 1
    while res <= lim:
        n = i + res * res
        blocks += [n]
        lim -= n
        i = n * 2
        res *= 2
    resBlocks = [0]
    for block in blocks:
        resBlocks += [resBlocks[-1] + block]
    return resBlocks
stairs = allBlocks()


for _ in range(int(input().strip())):
    N = int(input())
    ans = 0
    for stair in stairs:
        if stair <= N:
            ans += 1
        else:
            break
    print(ans - 1)