n = int(input())
A = input().split()
A = [int(i) for i in A]
if n != len(set(A)):
    print (-1)
else:
    B = A[:]
    B.sort()
    C = [n+100]*n
    for i in range (0,n):
        C[i] = A.index(B[i])
    D = [n+100]*n
    for i in range (0,n):
        D[C[i]] = A[C[(i+1)%n]]
    for x in D:
        print(x, end=" ")
    print()