import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
P = [int(x) for x in input().split()]

L = 2*N+100

A = [None] + [L*i for i in range(1,N+1)]
B = [None] + [L*(N+1-i) for i in range(1,N+1)]

for i,p in enumerate(P,1):
    A[p] += i

print(' '.join(map(str,A[1:])))
print(' '.join(map(str,B[1:])))