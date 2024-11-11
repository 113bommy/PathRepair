test=int(input())

for i in range(test):
    mx=[]
    for i in range(9):
        num=input()
        res = [int(x) for x in num]
        mx.append(res)
        
    for i in range(9):
        for j in range(9):
            if(mx[i][j]==1):
                mx[i][j]=2
    for i in range(9):
        for j in range(9):
            print(mx[i][j],end='')
        print()
