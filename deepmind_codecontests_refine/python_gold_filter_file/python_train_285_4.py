#!python3

import sys
iim = lambda: map(int, sys.stdin.readline().rstrip().split())
from heapq import heappush, heappushpop

def resolve():
    it = map(int, sys.stdin.read().split())

    T = next(it)
    ans = []
    for i in range(T):
        N = next(it)

        val = 0
        a1 = [[] for i in range(N)];
        a2 = [[] for i in range(N)];
        for i, v1, v2 in ((next(it)-1, next(it), next(it)) for i in range(N)):
            diff = v1 - v2
            if diff == 0 or i == N-1:
                val += v1
            elif diff > 0:
                a1[i].append(diff)
                val += v2
            else:
                i = N-1-i-1
                a2[i].append(-diff)
                val += v1

        for ax in (a1, a2):
            dq = []
            for i, aa in enumerate(ax):
                if not aa: continue
                for diff in aa:
                    ld = len(dq)
                    if ld <= i:
                        heappush(dq, diff)
                    else:
                        diff = heappushpop(dq, diff)

            val += sum(dq)

        ans.append(val)


    print(*ans, sep="\n")



if __name__ == "__main__":
    resolve()
