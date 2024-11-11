T=int(input())
for _ in range(T):
    n=int(input())
    matrix=[]
    for i in range(n):
        s=input()
        matrix.append(s)
    #print(matrix)
    if matrix[0][1]!=matrix[1][0] and matrix[n-2][n-1]!=matrix[n-1][n-2]:
        lis=[]
        if matrix[0][1]=='0':
            lis.append([1,2])
        else:
            lis.append([2,1])
        if matrix[n-2][n-1]=='1':
            lis.append([n-1,n])
        else:
            lis.append([n,n-1])
        print(2)
        for i in lis:
            print(*i)
    elif matrix[0][1]==matrix[1][0] and matrix[n-2][n-1]!=matrix[n-1][n-2]:
        print(1)
        if matrix[0][1]!=matrix[n-1][n-2]:
            print(n-1,n)
        else:
            print(n,n-1)
    elif matrix[0][1]!=matrix[1][0] and matrix[n-2][n-1]==matrix[n-1][n-2]:
        print(1)
        if matrix[0][1]!=matrix[n-1][n-2]:
            print(2,1)
        else:
            print(1,2)
    elif matrix[0][1]==matrix[1][0] and matrix[n-2][n-1]==matrix[n-1][n-2] and matrix[0][1]==matrix[n-2][n-1]:
        print(2)
        print(1,2)
        print(2,1)
    elif matrix[0][1]==matrix[1][0] and matrix[n-2][n-1]==matrix[n-1][n-2] and matrix[0][1]!=matrix[n-2][n-1]:
        print(0)
