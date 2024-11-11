def meguru_bisect(ok, ng):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok


N, Q = map(int, input().split())
S = input()
t, d = [], []
for i in range(Q):
    ti, di = input().split()
    t.append(ti)
    d.append(di)


def solve(i):
    for j in range(Q):
        if S[i] == t[j]:
            if d[j] == "L":
                i -= 1
            else:
                i += 1

            if i < 0 or i >= N:
                return 1
    return 0


left = meguru_bisect(-1, N)
right = meguru_bisect(N, -1)
print(max(right-left-1, 0))