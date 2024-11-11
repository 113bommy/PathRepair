import sys

sys.setrecursionlimit(10**5)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def MI(): return map(int, sys.stdin.buffer.readline().split())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
inf = 10**16
md = 10**9+7
# md = 998244353

h,w=MI()
aa=LLI(h)
bb=[[720720]*w for _ in range(h)]
for i in range(h):
    for j in range(w):
        if i+j&1:
            bb[i][j]+=aa[i][j]**4

for row in bb:
    print(*row)
