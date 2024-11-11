n = int(input())
A = list(map(int, input().split()))

def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

i = partition(A, 0, n-1)
print(' '.join(map(str, A[:i])) + ' [' + str(A[i]) + '] ' + ' '.join(map(str, A[i+1:])))