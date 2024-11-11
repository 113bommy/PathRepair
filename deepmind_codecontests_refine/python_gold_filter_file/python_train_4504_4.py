a=int(input())
for i in range(0,a):
    row,col=map(int,input().split())
    arr=[]
    for i in range(0,row):
        arr.append(list(map(int,input().split())))
    k=0
    if(arr[0][0]>2 or arr[0][col-1]>2 or arr[row-1][0]>2 or arr[row-1][col-1]>2):
        k=1
    else:
        for i in range(1,len(arr[0])-1):
            if(arr[0][i]>3):
                k=1 
            arr[0][i]=3
        for i in range(1,len(arr[0])-1):
            if(arr[row-1][i]>3):
                k=1
            arr[row-1][i]=3
        for i in range(1,row-1):
            if(arr[i][0]>3):
                k=1
            arr[i][0]=3
        for i in range(1,row-1):
            if(arr[i][len(arr[0])-1]>3):
                k=1
            arr[i][len(arr[0])-1]=3
    for i in range(1,row-1):
        for j in range(1,col-1):
            if(arr[i][j]>4):
                k=1 
            arr[i][j]=4
    if(k==1):
        print("NO")
    else:
        print("YES")
        arr[0][0]=2
        arr[0][col-1]=2
        arr[row-1][0]=2
        arr[row-1][col-1]=2
        for i in arr:
            print(" ".join(map(str,i)))
            