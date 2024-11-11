for i in range(int(input())):
    n,m = map(int,input().split())

    matrix = []
    for i in range(n):
        s = list(map(int,input().split()))
        matrix.append(s)

    rows = 0
    columns = 0
    for i in range(n):
        if sum(matrix[i])==0:
            rows+=1

    for i in range(m):
        temp=0
        for j in range(n):
            temp+=matrix[j][i]
        if temp==0:
            columns+=1

    if min(rows,columns)%2==1:
        print("Ashish")
    else:
        print("Vivek")
