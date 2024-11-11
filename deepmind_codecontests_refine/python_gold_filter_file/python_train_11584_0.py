import sys
import collections

input = sys.stdin.readline


def main():
    t = int(input())
    for _ in range(t):
        N, M = [int(x) for x in input().split()]
        P = [int(x) for x in input().split()]
        H = [int(x) for x in input().split()]
        XY = [[int(x) for x in input().split()] for _ in range(N - 1)]

        EDGE = [[] for j in range(N + 1)]

        for x, y in XY:
            EDGE[x].append(y)
            EDGE[y].append(x)

        q = collections.deque()
        q.append((0, 1))
        v = set()
        v.add(1)

        cnt = [0] * (N + 1)
        plus_cnt = [0] * (N + 1)
        ans = True
        while q:
            p, c = q[-1]

            if EDGE[c]:
                next = EDGE[c].pop()
                if next not in v:
                    q.append((c, next))
                    v.add(next)
            else:
                q.pop()
                cnt[c] += P[c - 1]
                cnt[p] += cnt[c]
                if (cnt[c] - H[c - 1]) % 2 == 1 or plus_cnt[c] - (cnt[c] - plus_cnt[c]) > H[c - 1] or cnt[c] < H[c - 1]:
                    ans = False
                    break
                else:
                    plus_cnt[p] += cnt[c] - ((cnt[c] - H[c - 1]) // 2)

        if ans:
            print("YES")
        else:
            print("NO")

if __name__ == '__main__':
    main()
