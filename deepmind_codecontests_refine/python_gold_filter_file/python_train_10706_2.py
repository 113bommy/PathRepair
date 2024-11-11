# coding: utf-8
import array, bisect, collections, copy, heapq, itertools, math, random, re, string, sys, time

sys.setrecursionlimit(10 ** 7)
INF = 10 ** 20
MOD = 10 ** 9 + 7


def II(): return int(input())
def ILI(): return list(map(int, input().split()))
def IAI(LINE): return [ILI() for __ in range(LINE)]
def IDI(): return {key: value for key, value in ILI()}


def read():
    N = II()
    edges = collections.defaultdict(list)
    for __ in range(N - 1):
        a, b = ILI()
        edges[a].append(b)
        edges[b].append(a)
    return N, edges


def solve(N, edges):
    queue_from_f = set()
    queue_from_s = set()
    queue_from_f.add(1)
    queue_from_s.add(N)

    n_node_f = 1
    snuke_bool = True

    visited_f = [False] * (N + 1)
    visited_s = [False] * (N + 1)
    visited_f[0], visited_f[1] = True, True
    visited_s[0], visited_s[N] = True, True

    while len(queue_from_f) != 0:
        f_next_queue = set()
        for i in queue_from_f:
            next_point = edges[i]
            for point in next_point:
                if snuke_bool and point in queue_from_s:
                    snuke_bool = False
                    visited_f[point] = True

                if visited_f[point]:
                    continue
                else:
                    f_next_queue.add(point)
                    visited_f[point] = True

        n_node_f += len(f_next_queue)
        queue_from_f = f_next_queue

        if snuke_bool:
            s_next_queue = set()
            for i in queue_from_s:
                next_point = edges[i]
                for point in next_point:
                    if point in queue_from_f:
                        visited_f[i] = True
                        snuke_bool = False
                        break

                    if visited_s[point]:
                        continue
                    else:
                        s_next_queue.add(point)
                        visited_s[point] = True

            queue_from_s = s_next_queue

    if n_node_f > N // 2:
        ans = "Fennec"
    else:
        ans = "Snuke"


    return ans


def main():
    params = read()
    print(solve(*params))


if __name__ == "__main__":
    main()
