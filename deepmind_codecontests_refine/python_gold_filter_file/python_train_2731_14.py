t=int(input())
for _ in range(t):
    a=[]
    for i in range(9):
        x=input()
        a.append(list(x))
    a[0][0]=a[0][1]
    a[1][4]=a[1][5]
    a[2][8]=a[2][7]
    a[3][1]=a[3][2]
    a[4][5]=a[4][6]
    a[5][6]=a[5][7]
    a[6][2]=a[6][3]
    a[7][3]=a[7][4]
    a[8][7]=a[8][8]
    for i in range(9):
        for j in range(9):
            print(a[i][j],end='')
        print()    