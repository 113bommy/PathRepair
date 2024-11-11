import bisect


def readline():
    return [int(x) for x in input().strip().split()]


def to_s(iterable):
    return (str(obj) for obj in iterable)


class Solver:
    def __init__(self):
        self.n = None
        self.k = None
        self.a = None
        self.sums = []

    def main(self):
        self.n, self.k = readline()
        self.a = [0] + readline()
        self.sums.append(0)
        for val in self.a[1:]:
            self.sums.append(self.sums[-1] + (val == 0))

        best_start, best_end = 0, -1
        for i in range(1, self.n + 1):
            end = bisect.bisect_right(self.sums, self.k + self.sums[i - 1], i)
            if end - i > best_end - best_start:
                best_start, best_end = i, end

        print(best_end - best_start)
        for i in range(best_start, best_end):
            self.a[i] = 1
        print(' '.join(to_s(self.a[1:])))


Solver().main()
