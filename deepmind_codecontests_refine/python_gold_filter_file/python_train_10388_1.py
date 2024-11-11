import sys
input = sys.stdin.readline

n = int(input())
A = [0] + list(map(int,input().split()))
C = [list(map(int,input().split())) for i in range(n-1)]


sys.setrecursionlimit(10**5 + 5)  # 再帰回数の上限！！


M = [[] for i in range(n+1)]
for i in range(n-1):
    M[C[i][0]].append(C[i][1])
    M[C[i][1]].append(C[i][0])


# 0-indexedの場合
V = [0] * (n+1)
# D = [-1] * (n+1)  # 自分を含む、子孫のノード数
ANS = [0] * (n+1)

R = [10**10] * (n+5)

import bisect

R[0] = A[1]
ANS[1] = 1

def des(x):
    # end = 1
    V[x] = 1
    # print(R[:10])


    for i in M[x]:
        if V[i] == 0:
            # print(i)
            # end = 0
            V[i] = 1
            ind = bisect.bisect_left(R, A[i])
            ma = R[ind]
            R[ind] = A[i]
            ANS[i] = bisect.bisect_left(R, 10**10-1)
            des(i)
            R[ind] = ma

    # if end == 1:
    #     print(R)
    #     ANS[x] = bisect.bisect_right(R, 10**10-1)

des(1)

for i in range(1, len(ANS)):
    print(ANS[i])