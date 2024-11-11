import functools
import time
from collections import Counter

def timer(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        stime = time.perf_counter()
        res = func(*args, **kwargs)
        elapsed = time.perf_counter() - stime
        print(f"{func.__name__} in {elapsed:.4f} secs")
        return res
    return wrapper

class solver:
    # @timer
    def __init__(self):
        pass

    def __call__(self):
        n = int(input())
        m = int(input())
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))

        def check(r):
            for i in range(n):
                r -= (m + r) / a[i]
                r -= (m + r) / b[(i + 1) % n]
            return r >= 0

        lo, hi = 0, 1e9
        for _ in range(100):
            md = (lo + hi) / 2
            if check(md):
                hi = md
            else:
                lo = md
        if not check(lo + 1e-6):
            print('-1')
        else:
            print(f'{lo:.9f}')

solver()()