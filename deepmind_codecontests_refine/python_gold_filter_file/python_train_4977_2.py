# 解説
def accumulate(a):
    su = 0
    yield su

    for x in a:
        su += x
        yield su


def solve_agc034c():
    from collections import namedtuple
    import sys
    input = sys.stdin.readline

    Test = namedtuple('Test', 'Aoki_score lower_bound upper_bound')
    Test.D_partial = lambda self, score: \
        self.lower_bound * score if score <= self.Aoki_score \
            else self.upper_bound * score - (self.upper_bound - self.lower_bound) * self.Aoki_score

    def is_ok(init_rest):
        """init_rest: 勉強に使える時間"""
        take, rest = divmod(init_rest, X)
        if take > N - 1:
            r = take - (N - 1)
            take = N - 1
            rest += r * X

        for i, partial_solve_test in enumerate(tests, start=1):
            when_full = partial_solve_test.D_partial(X)
            if i <= take:
                su = acc[take + 1] - when_full
            else:
                su = acc[take]

            when_partial = partial_solve_test.D_partial(min(X, rest))
            d = INIT_D + su + when_partial
            if d >= 0:
                return True

        return False

    def binary_search(*, ok, ng, is_ok):
        while abs(ok - ng) > 1:
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok

    N, X = map(int, input().split())
    tests = []
    for _ in range(N):
        row = map(int, input().split())
        tests.append(Test(*row))
    tests.sort(key=lambda test: test.D_partial(X), reverse=True)
    # 勝つ科目と負ける科目を決める
    # 勝つ科目は重要度をupper_boundにする
    # 負ける科目は重要度をlower_boundにする

    INIT_D = -sum(test.lower_bound * test.Aoki_score for test in tests)

    *acc, = accumulate(test.D_partial(X) for test in tests)

    res = binary_search(ok=10 ** 10, ng=-1, is_ok=is_ok)
    # D>=0となる勉強時間

    print(res)
    return


if __name__ == '__main__':
    solve_agc034c()
