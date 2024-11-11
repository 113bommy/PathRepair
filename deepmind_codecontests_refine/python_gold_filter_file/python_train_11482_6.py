import sys, collections, math, itertools, random
INF = sys.maxsize
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
mod = 1000000007

for _ in range(int(input())):
    n = int(input())
    arr = get_array()
    if all(arr[0] == arr[i] for i in range(1, n)):
        print('NO')
        continue
    print('YES')
    ss = 0
    for i in range(1, n):
        if arr[i] != arr[0]:
            ss = i
            break
    for i in range(1, n):
        if arr[i] != arr[0]:
            print(1, i+1)
        else:
            print(ss+1, i+1)