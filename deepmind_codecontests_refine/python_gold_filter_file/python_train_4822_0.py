from sys import stdin#, setrecursionlimit
from heapq import heappush, heappop, heapify, heappushpop
#setrecursionlimit(1000000)
lines = stdin.read().splitlines()
li = -1
def inp(): global li; li += 1; return lines[li]
def inpint(): global li; li += 1; return int(lines[li])
def inpints(change = 0): global li; li += 1; return [int(i) + change for i in lines[li].split()]
def inpfloat(): global li; li += 1; return float(lines[li])
def inpfloats(change = 0): global li; li += 1; return [float(i) + change for i in lines[li].split()]


t = inpint()
for T in range(t):
    n, k = inpints()
    if k > n // 2 or (n % 2 == 0 and k >= n // 2):
        print(-1); continue

    arr = []
    for i in range(k):
        arr.append(i)
        arr.append(n - i - 1)
    for i in range(k, n - k):
        arr.append(i)
    print(*[i + 1 for i in arr])
