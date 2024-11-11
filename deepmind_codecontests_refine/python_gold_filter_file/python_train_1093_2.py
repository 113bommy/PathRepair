from collections import defaultdict, deque, Counter, OrderedDict
from bisect import insort, bisect_right, bisect_left
import threading, sys

def main():
    n, k = map(int, input().split())
    s = [int(i) for i in input().split()]
    n = n - (2*k - n)
    if n <= 0:
        print(s[-1])
    else:
        ans = s[-1]
        for i in range(0,n//2):
            ans = max(ans,s[i]+s[n-1-i])
        print(ans)


if __name__ == "__main__":
    """sys.setrecursionlimit(400000)
    threading.stack_size(40960000)"""
    thread = threading.Thread(target=main)
    thread.start()
