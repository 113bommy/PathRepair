import os
import sys
from io import BytesIO, IOBase

_str = str
BUFSIZE = 8192


def str(x=b''):
    return x if type(x) is bytes else _str(x).encode()


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
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
            self.newlines = b.count(b'\n') + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


def inp():
    return sys.stdin.readline().rstrip()


def mpint():
    return map(int, inp().split(' '))


def itg():
    return int(inp())


# ############################## import
# from ACgenerator.Y_Testing import get_code
def tree_bfs(tree, start=0, flat=True) -> list:
    stack = [start]
    result = []
    while stack:
        new_stack = []
        if flat:
            result.extend(stack)
        else:
            result.append(stack)
        for node in stack:
            new_stack.extend(tree[node])
        stack = new_stack
    return result


def tree_postorder(tree, root=0, flat=True):
    """ children -> parent """
    return tree_bfs(tree, root, flat=flat)[::-1]


def to_tree(graph, root=0):
    """
    graph: [{child, ...}, ...]  (undirected)
    :return directed graph that parent -> children
    """
    stack = [[root]]
    while stack:
        if not stack[-1]:
            del stack[-1]
            continue
        parent = stack[-1].pop()
        for child in graph[parent]:
            graph[child].discard(parent)
        stack.append(list(graph[parent]))


def node_leaves(tree):
    """ :return: a list for the number of leaves under each node """
    n = len(tree)
    leaf = {i for i in range(n) if not tree[i]}
    result = [0] * n
    for i in tree_postorder(tree):
        result[i] += sum(map(result.__getitem__, tree[i])) + len(tree[i] & leaf)
    return result


def get_parent_list(tree):
    result = [0] * len(tree)
    for parent, children in enumerate(tree):
        for child in children:
            result[child] = parent
    return result


def ceil_a_divide_b(a, b):
    """
    a, b is integer, b != 0
    :return ceil(a / b)
    """
    if a > 0 and b < 0:
        a, b = -a, -b
    return (a - 1) // b + 1


# ############################## main
def solve():
    n = itg()
    tree = [set() for _ in range(n)]
    for i, j in enumerate(mpint(), 1):
        j -= 1
        tree[i].add(j)
        tree[j].add(i)
    to_tree(tree)
    values = list(mpint())
    leaves = node_leaves(tree)
    parents = get_parent_list(tree)
    ans = 0
    for i in reversed(range(n)):
        if leaves[i] == 0:
            ans = max(ans, values[i])
        else:
            ans = max(ans, ceil_a_divide_b(values[i], leaves[i]))
        values[parents[i]] += values[i]
    return ans


def main():
    # print("YES" if solve() else "NO")
    # print("yes" if solve() else "no")
    # solve()
    print(solve())
    # for _ in range(itg()):
    #     print(solve())


DEBUG = 0
URL = 'https://codeforces.com/contest/1436/problem/D'

if __name__ == '__main__':
    if DEBUG == 1:
        import requests  # ImportError: cannot import name 'md5' from 'sys' (unknown location)
        from ACgenerator.Y_Test_Case_Runner import TestCaseRunner

        runner = TestCaseRunner(main, URL)
        inp = runner.input_stream
        print = runner.output_stream
        runner.checking()
    elif DEBUG == 2:
        main()
    else:
        sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
        main()
# Please check!
