# @author 

import sys

class RWalk:
    def solve(self):

        MOD = 10 ** 9 + 7

        def mult(A, B):
            n, m, p = len(A), len(A[0]), len(B[0])
            assert(len(B) == m)
            C = [[0] * p for _ in range(n)]
            for i in range(n):
                for j in range(p):
                    for k in range(m):
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD

            return C

        def pow(A, k):
            n, m = len(A), len(A[0])
            if k == 0:
                return [[1 if i == j else 0 for j in range(m)] for i in range(n)]

            if k % 2 == 0:
                return pow(mult(A, A), k // 2)

            return mult(A, pow(A, k - 1))


        n, k = [int(_) for _ in input().split()]
        a = []
        for i in range(n):
            a.append([int(_) for _ in input().split()])

        print(sum([sum(line) for line in pow(a, k)]) % MOD)

solver = RWalk()
input = sys.stdin.readline

solver.solve()
