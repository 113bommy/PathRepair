n, k = map(int, input().split())
X = list(map(int, input().split()))
X = [x-1 for x in X]
if n == 1:
    print(0)
    exit()

from collections import defaultdict
First = defaultdict(lambda: k)
Last = defaultdict(lambda: -1)
for i, x in enumerate(X):
    First[x] = min(First[x], i)
    Last[x] = max(Last[x], i)
ans = 0
X = set(X)
for a in range(n):
    if a == 0:
        for d in range(0, 2):
            b = a+d
            if a != b:
                if First[a] >= Last[b]:
                    ans += 1
            else:
                if a not in X:
                    ans += 1
    elif a == n-1:
        for d in range(-1, 1):
            b = a+d
            if a != b:
                if First[a] >= Last[b]:
                    ans += 1
            else:
                if a not in X:
                    ans += 1
    else:
        for d in range(-1, 2):
            b = a+d
            if a != b:
                if First[a] >= Last[b]:
                    ans += 1
            else:
                if a not in X:
                    ans += 1
print(ans)
