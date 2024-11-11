import sys
input = sys.stdin.readline

def solve(N, M, X, D):
    # constraint from left, L - collides with rightmost even R or even L
    # constraint from right, R - collide with leftmost even L or even R
    # no more collisions when all only odd dist
    # dist between 2 facing opp direction = x[i] - x[j]
    # dist between 2 facing same direction = x[i] - x[j] + 2 * dist to wall
    # split into even/odd and left/right
    # eliminate those that don't turn first (left, and right)
    for i in range(len(X)):
        X[i] = (X[i], D[i], i)
    X.sort()

    ans = [-1 for _ in range(N)]

    # R L
    prevRight = [[] for _ in range(2)]
    for i in range(len(X)):
        x, d, idx = X[i]
        if d == 1:
            prevRight[x % 2].append((idx, x))
        elif prevRight[x % 2]:
            colliderIdx, colliderPos = prevRight[x % 2][-1]
            prevRight[x % 2].pop()
            dist = x - colliderPos
            ans[colliderIdx] = dist // 2
            ans[idx] = dist // 2

    # R L
    prevLeft = [[] for _ in range(2)]
    for i in range(len(X) - 1, -1, -1):
        x, d, idx = X[i]
        if ans[idx] != -1:
            continue
        if d == -1:
            prevLeft[x % 2].append((idx, x))
        elif prevLeft[x % 2]:
            colliderIdx, colliderPos = prevLeft[x % 2][-1]
            prevLeft[x % 2].pop()
            dist = colliderPos - x
            ans[colliderIdx] = dist // 2
            ans[idx] = dist // 2

    # eliminate those that left turn and right turn
    # L L
    prevLeft = [[] for _ in range(2)]
    for i in range(len(X)):
        x, d, idx = X[i]
        if ans[idx] != -1:
            continue
        if d == -1:
            if prevLeft[x % 2]:
                colliderIdx, colliderPos = prevLeft[x % 2][-1]
                prevLeft[x % 2].pop()
                dist = x - colliderPos + colliderPos * 2
                ans[colliderIdx] = ans[idx] = dist // 2
            else:
                prevLeft[x % 2].append((idx, x))

    # R R
    prevRight = [[] for _ in range(2)]
    for i in range(len(X) - 1, -1, -1):
        x, d, idx = X[i]
        if ans[idx] != -1:
            continue
        if d == 1:
            if prevRight[x % 2]:
                colliderIdx, colliderPos = prevRight[x % 2][-1]
                prevRight[x % 2].pop()
                dist = colliderPos - x + (M - colliderPos) * 2
                ans[colliderIdx] = dist // 2
                ans[idx] = dist // 2
            else:
                prevRight[x % 2].append((idx, x))

    # L R
    prevLeft = [[] for _ in range(2)]
    for i in range(len(X)):
        x, d, idx = X[i]
        if ans[idx] != -1:
            continue
        if d == -1:
            prevLeft[x % 2].append((idx, x))
    for x in prevLeft:
        x.reverse()

    for i in range(len(X) - 1, -1, -1):
        x, d, idx = X[i]
        if ans[idx] != -1:
            continue
        if d == 1:
            if prevLeft[x % 2]:
                colliderIdx, colliderPos = prevLeft[x % 2][-1]
                prevLeft[x % 2].pop()
                dist = x - colliderPos + (colliderPos) * 2 + (M - x) * 2
                ans[idx] = ans[colliderIdx] = dist // 2

    print(*ans)

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    X = list(map(int, input().split()))
    D = list(map(lambda x: -1 if x == 'L' else 1, input().split()))
    solve(N, M, X, D)
