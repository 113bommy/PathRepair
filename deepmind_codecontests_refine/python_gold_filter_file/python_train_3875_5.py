import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
W = [(i+1000007)**3 % 998244353 for i in range(N)]
AL, AR, BL, BR = [], [], [], []
for i in range(N):
    a, b, c, d = map(int, input().split())
    AL.append(a)
    AR.append(b)
    BL.append(c)
    BR.append(d)

def chk(L, R):
    D = {s:i for i, s in enumerate(sorted(list(set(L + R))))}
    X = [0] * 200200
    for i, l in enumerate(L): X[D[l]] += W[i]
    for i in range(1, 200200): X[i] += X[i-1]
    return sum([X[D[r]] * W[i] for i, r in enumerate(R)])

print("YES" if chk(AL, AR) == chk(BL, BR) else "NO")