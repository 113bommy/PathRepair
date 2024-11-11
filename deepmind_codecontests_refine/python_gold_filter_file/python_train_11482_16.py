from collections import deque

def connect_asimilar(pts):
    n = len(pts)
    graph = [[] for i in range(n)]
    for i, pt in enumerate(pts):
        if pts[i] != pts[0]:
            graph[0].append(i)
    j = 1
    while  j < n and pts[j] == pts[0]:
        j += 1
    if j == n:
        return []
    for i in range(1, n):
        if pts[i] == pts[0]:
            graph[j].append(i)
    return graph


if __name__ == "__main__":
    t = int(input())
    cases = []
    for i in range(t):
        input()
        cases.append(list(map(int, input().split(' '))))
    for case in cases:
        ret = connect_asimilar(case)
        if len(ret) == 0:
            print("NO")
        else:
            print("YES")
            for i, row in enumerate(ret):
                for val in row:
                    print(i + 1, end=' ')
                    print(val + 1)
