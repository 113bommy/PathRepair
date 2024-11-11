import sys
input = lambda: sys.stdin.readline().rstrip()
P = 10 ** 40 + 121
N = int(input())
X = sorted([input()[::-1] for _ in range(N)], key = len)

D = {}
ans = 0
for x in X:
    L = [0] * 26
    T, a = x[:-1], ord(x[-1]) - 97
    h = 0
    for t in T:
        if h in D:
            for i in range(26):
                L[i] += D[h][i]
        b = ord(t) - 97
        ans += L[b]
        L[b] = 0
        
        h = (h + b + 135) * 71 % P
    ans += L[a]
    if h in D:
        D[h][a] += 1
    else:
        D[h] = [0] * 26
        D[h][a] = 1
    
print(ans)