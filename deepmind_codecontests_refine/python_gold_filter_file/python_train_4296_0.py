from heapq import *
import sys

int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def ng():
    print("NO")
    exit()

n, k = MI()
if (n,k)==(1,0):
    print("YES")
    print(0)
    exit()

ans = [0] * n
popcnt = lambda x: bin(x).count("1")

if n & 1 == 0 or n < 2 * k + 3 or (popcnt(n + 1) > 1 and k == 0): ng()

u = 0
if popcnt(n + 1 - 2 * (k - 1)) == 1:
    for v in range(1, 4): ans[v] = v // 2+1
    k -= 1
    if n - 4 < 2 * k + 3 or k==0 or n<11: ng()
    ans[4] = 1
    u = 4
#print(n, k, u, ans)

for _ in range(k - 1):
    ans[u + 1] = ans[u + 2] = u+1
    u += 2
#print(n, k, u, ans)

for v in range(1,n-u):ans[v+u]=(v-1)//2+u+1

print("YES")
print(*ans)
