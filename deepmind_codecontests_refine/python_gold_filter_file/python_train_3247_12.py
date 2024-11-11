import math
import sys
from collections import defaultdict,Counter,deque
import bisect
#sys.setrecursionlimit(1000000)
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
ilele = lambda: map(int,input().split())
alele = lambda: list(map(int, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
#def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#INF = 10 ** 18
#MOD = 1000000000 + 7
from itertools import accumulate,groupby
dp = []

for _ in range(int(input())):
    N = int(input())
    A =input()
    B= input();pos=0;f=0
    for i in range(-1,N-1):
        if pos==0:
            if A[i+1] == "1" or A[i+1] == "2":
                pos = 0
            else:
                if B[i+1] != "1" and B[i+1] != "2":
                    pos = 1
                else:
                    f=1
                    break
        else:
            if B[i+1] == "1" or B[i+1] == "2":
                pos = 1
            else:
                if A[i+1] != "1" and A[i+1] != "2":
                    pos = 0
                else:
                    f=1
                    break
    if f==1 or pos == 0:
        print("NO")
    else:
        print("YES")
            
        