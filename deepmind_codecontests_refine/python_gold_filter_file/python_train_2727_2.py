import sys
import os
import math

def READ(fileName):
    sys.stdin = open('in.txt')


if __name__ == "__main__":
    #READ('in.txt')
    
    while True:
        try:
            n, m = map(int, input().split())
        except:
            break
        
        ns  = list(map(int, input().split()))
        ms  = list(map(int, input().split()))

        mat = [[-1 for x in range(m)] for y in range(n)]

        for i in range(n):
            now = ns[i]
            if now == 0:
                mat[i][0] = 0
            else:
                for j in range(0, now, 1):
                    mat[i][j] = 1
                if now < m:
                    mat[i][now] = 0
                
        isValid = True

        for i in range(m):
            now = ms[i]
            if now == 0:
                if mat[0][i] == 1:
                    isValid = False
                    break
                else:
                    mat[0][i] = 0
            else:
                for j in range(0, now, 1):
                    if mat[j][i] == 0:
                        isValid = False
                        break
                    else:
                        mat[j][i] = 1
                if now < n:
                    if mat[now][i] == 1:
                        isValid = False
                    else:
                        mat[now][i] = 0

        if isValid == False:
            print('0')
        else:
            unreserved = 0
            for row in mat:
                unreserved += row.count(-1)
            ans = pow(2, unreserved, 1000000007)
            print(ans)
                
        #print(ans)
        # print('after')
        # for i in range(n):
        #     now = ns[i]
        #     for j in range(m):
        #         print(mat[i][j], end=' ')
        #     print('')
        

    pass