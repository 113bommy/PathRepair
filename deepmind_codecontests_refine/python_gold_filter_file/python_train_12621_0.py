import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

from collections import deque
def dfs(alpha, id):
    """Depth First Search on a graph!"""
    stack = [alpha]
    cycle = None
    while stack:
        v = stack[-1]
        if not visited[v]:
            visited[v] = True
            u = graph[v]
            if 1:
                if not visited[u]:
                    stack.append(u)
                elif visited[u] and ids[u] != -1:
                    id = ids[u]
                    cycleid = u
                else:
                    cycle = (u, v)

        else:
            break
    if not cycle:
    #print(cycleid, result)
        result = stack
        for i in range(len(result)):
            ids[result[i]] = id
            cyclelength[result[i]] = cyclelength[cycleid]
            cycledistance[result[i]] = (cycledistance[cycleid] - (len(result)-i)) \
                                       % cyclelength[result[i]]
    else:
        #print(cycle, result, stack)
        index = []
        result = stack
        for i in range(len(result)):
            ids[result[i]] = id
            if result[i] == cycle[0] or result[i] == cycle[1]:
                index += [i]
        for i in range(len(result)):
            if i < index[0]:
                cycledistance[result[i]] = (i - index[0]) % (index[1] - index[0] + 1)
            else:
                cycledistance[result[i]] = (i - index[0]) % (index[1] - index[0] + 1)
            cyclelength[result[i]] = index[1] - index[0] + 1


for _ in range(int(input())):
    n, m = map(int, input().split())
    colors = [-1]
    for i in range(n):
        colors += [int(k) for k in input()]
    graph = [0]*(n*m + 1)
    for i in range(n):
        line = input()
        for j in range(m):
            if line[j] == 'R':
                graph[i*m + j + 1] = i*m + j + 2
            elif line[j] == 'L':
                graph[i*m + j + 1] = i*m + j
            elif line[j] == 'U':
                graph[i*m + j + 1] = (i-1)*m + j + 1
            else:
                graph[i*m + j + 1] = (i+1)*m + j + 1
    visited = [False] * len(graph)
    ids = [-1] * len(graph)
    cycledistance = [0] * len(graph)
    cyclelength = [0] * len(graph)
    id = 0
    oo = []
    for i in range(1, len(graph)):
        if not visited[i]:
            dfs(i, id)
            if ids[i] == id:
                id += 1
                oo += [[0]*cyclelength[i]]
    #print(cycledistance)
    #print(cyclelength)
    #print(ids)
    #print(graph)
    black = 0
    white = 0
    for i in range(1, len(graph)):
        if colors[i] == 0:
            if not oo[ids[i]][cycledistance[i]]:
                black += 1
                oo[ids[i]][cycledistance[i]] = 1
    for i in range(1, len(graph)):
        if colors[i] == 1:
            if not oo[ids[i]][cycledistance[i]]:
                white += 1
                oo[ids[i]][cycledistance[i]] = 1
    print(white+black, black)