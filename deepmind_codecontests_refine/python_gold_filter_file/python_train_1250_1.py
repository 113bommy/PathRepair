# -*- coding: utf-8 -*-


def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def main():
    n = int(input())
    A = [int(e) for e in input().split()]
    p = 0
    idx = partition(A, p, n - 1)
    A = [str(e) for e in A]
    A[idx] = "[{}]".format(A[idx])
    return " ".join(A)


print(main())