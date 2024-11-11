import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
#sys.setrecursionlimit(200000000)
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
ilele = lambda: map(int,input().split())
alele = lambda: list(map(int, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
#def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])
    
N = int(input())
S = input()
A = alele()
h,a,r,d = 0,0,0,0
for i in range(N):
    if S[i] == 'h':
        h += A[i]
    elif S[i] == 'a':
        a = min(h,a + A[i])
    elif S[i] == 'r':
        r = min(a, r + A[i])
    elif S[i] == 'd':
        d = min(r, d + A[i])
print(d)