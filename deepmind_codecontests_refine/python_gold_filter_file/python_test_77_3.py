import sys
sys.setrecursionlimit(100000)
 
def _r(): return sys.stdin.buffer.readline()
def rs(): return _r().decode('ascii').strip()
def rn(): return int(_r())
def rnt(): return map(int, _r().split())
def rnl(): return list(rnt())

def solve(n, m, mat):
    dp, color = [[0]*m for _ in range(n)], 1
    def _color(r, c, color):
        stack, colored = [(r, c)], 1
        dp[r][c] = color
        while stack:
            r, c = stack.pop()
            for dr, dc, mask in ((-1, 0, 8), (0, 1, 4), (1, 0, 2), (0, -1, 1)):
                nr, nc = r+dr, c+dc
                if (mat[r][c] & mask) == 0 and dp[nr][nc] == 0:
                    dp[nr][nc] = color
                    colored += 1
                    stack.append((nr, nc))
        return colored
    sol = []
    for r in range(n):
        for c in range(m):
            if dp[r][c] == 0:
                sol.append(_color(r, c, color))
                color += 1
    return sorted(sol, reverse=True)

n, m = rnt()
mat = []
for _ in range(n):
    mat.append(rnl())
print(' '.join(map(str, solve(n, m, mat))), '')
 
# for _ in range(rn()):
#     n = rn()
#     edges = [rnt() for _ in range(n-1)]
#     print(solve(n, edges))