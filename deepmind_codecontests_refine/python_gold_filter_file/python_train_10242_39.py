mat=[]
for i in range(3):
    mat.append(list(map(int,input().rstrip().split())))

temp=[[1 for i in range(3)]for j in range(3)]
    
for i in range(3):
    for j in range(3):
        if mat[i][j]%2==1:
            temp[i][j]+=1
            if i+1<3:
                temp[i+1][j]+=1
            if j+1<3:
                temp[i][j+1]+=1
            if i-1>-1:
                temp[i-1][j]+=1
            if j-1>-1:
                temp[i][j-1]+=1
for i in range(3):
    for j in range(3):
        print(temp[i][j]%2,end="")
    print()