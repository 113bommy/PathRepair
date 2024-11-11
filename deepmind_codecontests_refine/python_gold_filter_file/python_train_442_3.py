import sys
from collections import deque

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    A = list(map(int, input().split()))

    last = [None, None]
    que = deque([])
    H = 1
    res = []
    for i in reversed(range(n)):
        if A[i] == 0:
            continue
        elif A[i] == 1:
            que.append([i, H])
            res.append([i, H])
            H += 1
        elif A[i] == 2:
            if not que:
                print(-1)
                exit()
            _, h = que.pop()
            res.append([i, h])
            last = [i, h]
        else:
            if last == [None, None]:
                if not que:
                    print(-1)
                    exit()
                else:
                    last = que.pop()
            res.append([i, H])
            res.append([last[0], H])
            last = [i, H]
            H += 1

    print(len(res))
    for j in res:
        print(n - j[1] + 1, j[0] + 1)


if __name__ == '__main__':
    resolve()
