# DEFINING SOME GOOD STUFF
import heapq
import sys
from math import *
import threading
from heapq import *
from itertools import count
from pprint import pprint
from collections import defaultdict

'''
    intialise defaultdict by any kind of value by default you want to take ( int -> 0 | list -> [] )
'''
from heapq import heapify, heappop, heappush

sys.setrecursionlimit(300000)
# threading.stack_size(10**8)
'''
-> if you are increasing recursionlimit then remember submitting using python3 rather pypy3
-> sometimes increasing stack size don't work locally but it will work on CF
'''

mod = 10 ** 9+7
inf = 10 ** 15
decision = ['NO', 'YES']
yes = 'YES'
no = 'NO'

# ------------------------------FASTIO----------------------------
import os

from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
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
            self.newlines = b.count(b"\n")+(not b)
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
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")


# _______________________________________________________________#

def npr(n, r):
    return (factorial(n)%mod) // (factorial(n-r)%mod) if n >= r else 0


def ncr(n, r):
    return (factorial(n)%mod) // ((factorial(r)%mod) * (factorial(n-r)%mod)) if n >= r else 0


def lower_bound(li, num):
    answer = -1
    start = 0
    end = len(li)-1

    while (start <= end):
        middle = (end+start) // 2
        if li[middle] >= num:
            answer = middle
            end = middle-1
        else:
            start = middle+1
    return answer  # min index where x is not less than num


def upper_bound(li, num):
    answer = -1
    start = 0
    end = len(li)-1

    while (start <= end):
        middle = (end+start) // 2

        if li[middle] <= num:
            answer = middle
            start = middle+1

        else:
            end = middle-1
    return answer  # max index where x is not greater than num


def abs(x):
    return x if x >= 0 else -x


def binary_search(li, val):
    # print(lb, ub, li)
    ans = -1
    lb = 0
    ub = len(li)-1
    while (lb <= ub):
        mid = (lb+ub) // 2
        # print('mid is',mid, li[mid])
        if li[mid] > val:
            ub = mid-1
        elif val > li[mid]:
            lb = mid+1
        else:
            ans = mid  # return index
            break
    return ans


def kadane(x):  # maximum sum contiguous subarray
    sum_so_far = 0
    current_sum = 0
    for i in x:
        current_sum += i
        if current_sum < 0:
            current_sum = 0
        else:
            sum_so_far = max(sum_so_far, current_sum)
    return sum_so_far


def pref(li):
    pref_sum = [0]
    for i in li:
        pref_sum.append(pref_sum[-1]+i)
    return pref_sum


def SieveOfEratosthenes(n):
    prime = [{1, i} for i in range(n+1)]
    p = 2
    while (p <= n):
        for i in range(p * 2, n+1, p):
            prime[i].add(p)
        p += 1
    return prime


def primefactors(n):
    factors = []
    while (n % 2 == 0):
        factors.append(2)
        n //= 2
    for i in range(3, int(sqrt(n))+1, 2):  # only odd factors left
        while n % i == 0:
            factors.append(i)
            n //= i
    if n > 2:  # incase of prime
        factors.append(n)
    return factors


def prod(li):
    ans = 1
    for i in li:
        ans *= i
    return ans


def sumk(a, b):
    print('called for', a, b)
    ans = a * (a+1) // 2
    ans -= b * (b+1) // 2
    return ans

def sumi(n):
    ans = 0
    if len(n) > 1:
        for x in n:
            ans += int(x)
        return ans
    else:
        return int(n)

def checkwin(x, a):
    if a[0][0] == a[1][1] == a[2][2] == x:
        return 1
    if a[0][2] == a[1][1] == a[2][0] == x:
        return 1
    if (len(set(a[0])) == 1 and a[0][0] == x) or (len(set(a[1])) == 1 and a[1][0] == x) or (len(set(a[2])) == 1 and a[2][0] == x):
        return 1
    if (len(set(a[0][:])) == 1 and a[0][0] == x) or (len(set(a[1][:])) == 1 and a[0][1] == x) or (len(set(a[2][:])) == 1 and a[0][0] == x):
        return 1
    return 0

# _______________________________________________________________#


# def main():
karmanya = int(input())
# karmanya = 1
# divisors = SieveOfEratosthenes(200010)
# print(divisors)
while karmanya != 0:
    karmanya -= 1
    # n = int(input())
    n,x,t= map(int, input().split())
    # n,m= map(int, input().split())
    # k = int(input())
    # a = [int(x) for x in input()]
    # a = list(map(int, input().split()))
    # b = list(map(int, input().split()))
    # c = list(map(int, input().split()))
    # d = defaultdict(int)
    p = min(n, t//x) # number of students in a particular interval of paper
    ans = p*(p-1)//2 + p*(n-p)
    print(ans)


# sum of numbers from 1 to p-1 = p*(p-1)//2









































































































































# t = threading.Thread(target=main)
# t.start()
# t.join()