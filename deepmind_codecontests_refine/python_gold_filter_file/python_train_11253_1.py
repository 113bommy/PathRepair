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
        minv = n + 1
        mini = n
        for l in range(1, n + 1):
            v = l + (n + l - 1) // l
            if v < minv:
                minv = v
                mini = l       

        ref = [i + 1 for i in range(n)]
        l = mini        
        res = list()
        p = n - 1
        while p >= 0:
            pp = max(0, p - l + 1)            
            res.extend(ref[pp:p + 1])
            p = pp - 1
        print(' '.join(map(str, res)))


solver()()