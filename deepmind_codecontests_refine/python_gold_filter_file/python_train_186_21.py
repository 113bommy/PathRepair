def solve(N, K, Q, As, X):
    mins = []
    tmp = []
    for A in As:
        if A >= X:
            tmp.append(A)
        else:
            if len(tmp) >= K:
                tmp.sort()
                mins.extend(tmp[:len(tmp)-K+1])
            tmp = []
    if len(tmp) >= K:
        tmp.sort()
        mins.extend(tmp[:len(tmp)-K+1])

    if len(mins) < Q:
        return None
    mins.sort()
    taken = mins[:Q]
    return taken[-1] - taken[0]


N, K, Q = map(int, input().split())
As = [int(x) for x in input().split()]

ans = -1
for A in As:
    cand = solve(N, K, Q, As, A)
    if cand is not None and (ans == -1 or ans > cand):
        ans = cand

print(ans)
