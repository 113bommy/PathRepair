import sys

n, s = map(int, input().split())

ok, ng = 10**18+100, -1
while abs(ok - ng) > 1:
    mid = (ok + ng) >> 1
    if mid - sum(map(int, str(mid))) >= s:
        ok = mid
    else:
        ng = mid

print(max(0, n - ok + 1))
