N, K = map(int, input().split())

A = list(map(int, input().split()))
F = list(map(int, input().split()))

A.sort()
F.sort(reverse = True)

def calc(x): #全てx以下にするために何回変える必要があるか
    tmp = 0
    for a, f in zip(A, F):
        tmp += max(0, a - (x // f))
    return tmp

ng = -1
ok = 10 ** 18
while ok - ng > 1:
    mid = (ok + ng) // 2
    if calc(mid) <= K:
        ok = mid
    else:
        ng = mid

print (ok)