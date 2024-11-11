from sys import stdin, stdout
import traceback
from collections import deque

read = lambda: stdin.readline().strip()
write = stdout.write
writeln = lambda x: write(str(x) + "\n")


def reads(typ=int):
    return list(map(typ, read().split()))


class Sol:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
        self.ret = 30000
        self.best = (1, 1, 1)

    @classmethod
    def input(cls):
        a, b, c = reads()
        return cls(a, b, c)

    def solve(self):
        # c = mb
        # b = na
        for n in range(1, 11001):
            for m in range(1, 11000 // n + 1):
                for base in range(1, 11000 // (m * n) + 1):
                    self.check(n, m, base)
        return self.ret, self.best

    def check(self, n, m, base):
        new_a = base
        new_b = base * n
        new_c = base * n * m
        ret = abs(new_a - self.a) + abs(new_b - self.b) + abs(new_c - self.c)
        if ret < self.ret:
            self.ret = ret
            self.best = (new_a, new_b, new_c)


if __name__ == "__main__":
    try:
        for _ in range(int(read())):
            res, best = Sol.input().solve()
            writeln(res)
            writeln(" ".join([str(x) for x in best]))
    except Exception as e:
        print("Got exception:", repr(e))
        print(traceback.format_exc())
