import sys
import math
input = lambda:sys.stdin.readline().strip()
t = int(input())
while t:
    t-=1
    n,m,x,y = map(int,input().split())
    mat = [[] for _ in range(n)]
    whites = 0
    for i in range(n):
        inp = input()
        for j in inp:
            if j=='.':
                whites+=1
                mat[i].append(1)
            else:
                mat[i].append(0) 
    if 2*x<=y:
        print(whites*x)
    else:
        price = 0
        for i in range(n):
            j = 0
            while j<m:
                if mat[i][j]==0:
                    j+=1
                    continue
                if j+1<m:
                    if mat[i][j+1]==1:
                        price+=y
                        j+=1
                    else:
                        price+=x
                else:
                    price+=x 
                j+=1
        print(price)