import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
#sys.setrecursionlimit(200000000)
int1 = lambda x: int(x) - 1
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
ilele = lambda: map(int,input().split())
alele = lambda: list(map(int, input().split()))
ilelec = lambda: map(int1,input().split())
alelec = lambda: list(map(int1, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])


N=int(input())
A = deque()
Ans =0
top = 0
for i in range(2*N):
    s = input()
    if s == "remove":
        top += 1
        if len(A) == 0:
            continue
        elif top==A[-1]:
            A.pop()
        else:
            Ans += 1
            A = deque()
    else:
        _,n = s.split(" ")
        n = int(n)
        A.append(n)
print(Ans)
        