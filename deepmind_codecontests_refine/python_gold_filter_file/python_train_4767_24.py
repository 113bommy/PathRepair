#!/usr/bin/env python3
import sys
from itertools import accumulate
def solve(k: int, q: int, d: "List[int]", n: "List[int]", x: "List[int]", m: "List[int]"):
    for query in range(q):
        N,X,M = n[query],x[query],m[query]
        count = [0]*k
        D = [0]*k
        c = 0
        for i in range(k):
            D[i] = d[i]%M
            if D[i] == 0:
                c += 1
            count[i] = c
        accum = list(accumulate(D))
        SUMD = accum[-1]
        COUNTD = count[-1]

        if (N-1)%k == 0:
            last = X+((N-1)//k)*SUMD
            equal_count = COUNTD*((N-1)//k)
        else:
            last = X + SUMD*((N-1)//k) + accum[(N-1)%k-1]
            equal_count = COUNTD*((N-1)//k)+count[(N-1)%k-1]
        
        shounari_count = last//M - X//M
        dainari_count = N-shounari_count-equal_count-1
        print(dainari_count)
    return

def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    k = int(next(tokens))  # type: int
    q = int(next(tokens))  # type: int
    d = [int(next(tokens)) for _ in range(k - 1 - 0 + 1)]  # type: "List[int]"
    n = [int()] * (q)  # type: "List[int]"
    x = [int()] * (q)  # type: "List[int]"
    m = [int()] * (q)  # type: "List[int]"
    for i in range(q):
        n[i] = int(next(tokens))
        x[i] = int(next(tokens))
        m[i] = int(next(tokens))
    solve(k, q, d, n, x, m)

if __name__ == '__main__':
    main()
