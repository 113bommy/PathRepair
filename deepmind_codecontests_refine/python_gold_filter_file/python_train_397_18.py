# -*- coding: utf-8 -*-
import sys
# sys.setrecursionlimit(10**6)
# buff_readline = sys.stdin.buffer.readline
buff_readline = sys.stdin.readline
readline = sys.stdin.readline

INF = 2**62-1


def read_int():
    return int(buff_readline())


def read_int_n():
    return list(map(int, buff_readline().split()))


def read_float():
    return float(buff_readline())


def read_float_n():
    return list(map(float, buff_readline().split()))


def read_str():
    return readline().strip()


def read_str_n():
    return readline().strip().split()


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


@mt
def slv(H, W, K, A):
    for i in range(H):
        for j in range(W):
            if A[i][j] == 'S':
                s = (i, j)
    from collections import deque
    q = deque([s])
    d = [[None] * W for _ in range(H)]
    d[s[0]][s[1]] = 0
    r = [s]
    while q:
        x, y = q.popleft()
        for vx, vy in [(x-1, y), (x, y-1), (x, y+1), (x+1, y)]:
            if not (0 <= vx < H and 0 <= vy < W):
                continue
            if A[vx][vy] == '#':
                continue
            if d[vx][vy] is not None:
                continue
            c = d[x][y]
            if c + 1 <= K:
                q.append((vx, vy))
                d[vx][vy] = c + 1
                r.append((vx, vy))


    ans = INF
    for x, y in r:
        t = min(abs(x), abs(x-H+1), abs(y), abs(y-W+1))
        ans = min(ans, t)

    return 1 + -(-ans // K)


def main():
    H, W, K = read_int_n()
    A = [read_str() for _ in range(H)]
    print(slv(H, W, K, A))


if __name__ == '__main__':
    main()
