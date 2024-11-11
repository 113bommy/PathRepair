from sys import *
setrecursionlimit(100000)
for _ in range(int(input())):
    n, m = map(int, input().split())
    A = {}
    A[m] = set()
    for i in range(n - 1):
        a, b = map(int, input().split())
        if a in A:
            A[a].add(b)
        else:
            A[a] = set()
            A[a].add(b)
        if b in A:
            A[b].add(a)
        else:
            A[b] = set()
            A[b].add(a)
    if len(A[m]) == 0 or len(A[m]) == 1:
        print('Ayush')
    else:
        if (n - 2) % 2 == 1:
            print('Ashish')
        else:
            print('Ayush')