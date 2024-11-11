from bisect import bisect_left
import sys
sys.setrecursionlimit(10**6)
N, K, A, B = map(int, input().split())
k = sorted(map(int, input().split()))
base_length = 2**N

def hoge(l, r):
    avengers = bisect_left(k, r) - bisect_left(k, l)
    size = r-l
    power = A if not avengers else B*avengers*size
    if not avengers or r-l == 1:
        return power
    else:
        mid = (r+l)//2
        return min(power, hoge(l, mid)+hoge(mid, r))


print(hoge(1, base_length+1))