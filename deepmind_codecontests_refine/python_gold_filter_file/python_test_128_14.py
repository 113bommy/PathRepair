import sys
import math
from itertools import accumulate
    
def read_string(): return sys.stdin.readline().strip()
def read_int_arr(): return list(map(int, sys.stdin.readline().strip().split()))
def read_ints(): return map(int, sys.stdin.readline().strip().split())
    
def solve():
    n = int(input())

    if n % 2 == 0:
        print(n-3, 2, 1)
    else:
        for a in range(n-4, (n-1) // 2 - 1, -2):
            if math.gcd(a, n-1-a) == 1:
                print(a, n-1-a, 1)
                return
        


    
if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()