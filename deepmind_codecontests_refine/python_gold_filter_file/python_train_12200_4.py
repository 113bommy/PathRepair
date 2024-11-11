from math import sqrt
def divis(a):
    A = [1,a]
    
    for i in range(2,round(sqrt(a)+1)):
        if a % i == 0:
            A.append(i)
            if i**2 != a:
                A.append(a // i)
            
    return sorted(A)
def check(x):
    B = [x]
    for j in range(n):
        if A[0][j]!=0:
            B.append(A[0][j]//x)
    for i in range(1,n):
        for j in range(n):
            if A[i][j] != 0:
                if A[i][j]!=B[i]*B[j]:
                    return False,[]
    return True,B
                

n = int(input())
A = []
for i in range(n):
    A.append(list(map(int,input().split())))
Div = divis(A[0][1])

for i in range(len(Div)):
    res,C = check(Div[i])
    if res:
        print(*C)
        break