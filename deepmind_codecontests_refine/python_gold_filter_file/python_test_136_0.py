t = int(input())
for _ in range(t):
    n = int(input())
    B = list(map(int,input().split()))
    nsum = n * (n+1) / 2
    if sum(B) % nsum == 0:
        S = sum(B) // nsum
        ans = list()
        ll = 0
        for i in range(n):
            if i == 0:
                kk = B[n-1]
            else:
                kk = B[i-1]
            k = ((S-B[i]+kk) / n)
            if k < 1 or k != int(k):
                ll = 1
                break
            ans.append(k)
        if ll == 1:
            print('NO')
        else:
            print('YES')
            for i in ans:
                print(int(i),end=' ')
    else:
        print('NO')









# import numpy as np
# def eliminate(r1, r2, col, target=0):
#     fac = (r2[col]-target) / r1[col]
#     for i in range(len(r2)):
#         r2[i] -= fac * r1[i]

# def gauss(a):
#     for i in range(len(a)):
#         if a[i][i] == 0:
#             for j in range(i+1, len(a)):
#                 if a[i][j] != 0:
#                     a[i], a[j] = a[j], a[i]
#                     break
#             else:
#                 raise ValueError("Matrix is not invertible")
#         for j in range(i+1, len(a)):
#             eliminate(a[i], a[j], i)
#     for i in range(len(a)-1, -1, -1):
#         for j in range(i-1, -1, -1):
#             eliminate(a[i], a[j], i)
#     for i in range(len(a)):
#         eliminate(a[i], a[i], i, target=1)
#     return a

# def inverse(a):
#     tmp = [[] for _ in a]
#     for i,row in enumerate(a):
#         assert len(row) == len(a)
#         tmp[i].extend(row + [0]*i + [1] + [0]*(len(a)-i-1))
#     gauss(tmp)
#     ret = []
#     for i in range(len(tmp)):
#         ret.append(tmp[i][len(tmp[i])//2:])
#     return ret

# t = int(input())

# for _ in range(t):
#     n = int(input())
#     b = list(map(int,input().split()))
#     B = np.array([[b[i]] for i in range(n)])
#     a = [1]
#     for i in range(n, 1, -1):
#         a.append(i)
#     A = list()
#     A.append(a)
#     for i in range(1, n):
#         temp = A[i-1][0:n-1]
#         temp = [A[i-1][-1]] + temp
#         A.append(temp)
#     Ar = np.array(A)
#     # invA = np.linalg.inv(Ar)
#     # print(invA)
#     matrix = A
#     inn = inverse(A)
#     # print(inn)
#     # invA = getMatrixInverse(A)
#     # print(list(invA))
#     invAA = np.array(inn)
#     mat1, mat2 = list(invAA), list(B)
#     result = [[0] for i in range(n)]
#     for x in range(len(mat1)):
#        # iterate through columns of c2
#        for y in range(len(mat2[0])):
#            # iterate through rows of r2
#            for z in range(len(mat2)):
#                 result[x][y] += mat1[x][z] * mat2[z][y]
#     C = result
#     kk = 0
#     for i in range(n):
#         if int(round(C[i][0])) < 1:
#             kk = 1
#     if kk == 1:
#         print('NO')
#     else:
#         print('YES')
#         for i in range(n):
#             print(int(round(C[i][0])), end=' ')
#         print()
