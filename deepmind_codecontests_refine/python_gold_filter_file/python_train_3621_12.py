import sys
sys.setrecursionlimit(10**9)

N = int(input())
A = list(map(int,input()))
X = 2 in A

while len(A) > 1:
    if len(A) % 2 == 1:
        for i in range(len(A)-1):
            A[i] = abs(A[i]-A[i+1])
        A.pop()
    B = []
    for i in range(len(A)//2):
        B.append(abs(A[i*2]-A[i*2+1]))
    A = B[:]

if X:
    A[0] %= 2
print(A[0])
