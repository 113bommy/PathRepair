from sys import stdin,stderr
def rl():
    return [int(w) for w in stdin.readline().split()]

n,q = rl()
lava = [[False] * (n+2) for r in (0,1)]
blocks = set()
for i in range(q):
    r,c = rl()
    r -= 1
    lava[r][c] = not lava[r][c]
    r1 = 1 - r
    for c1 in (c-1,c,c+1):
        block_id = 8*(c+c1)+(2*r-1)*(c1-c)
        if lava[r][c] and lava[r1][c1]:
            blocks.add(block_id)
        else:
            try:
                blocks.remove(block_id)
            except:
                pass
    print("No" if blocks else "Yes")
