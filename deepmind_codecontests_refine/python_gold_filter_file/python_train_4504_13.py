for _ in range(int(input())):
    n,m=map(int,input().split())
    mat=[]
    for i in range(n):
        mat.append(list(map(int,input().split())))
    for i in range(n):
        for j in range(m):
            flag=0
            if mat[i][j]>0:
                c=0
                if i-1>=0:c+=1
                if i+1<n:c+=1
                if j-1>=0:c+=1
                if j+1<m:c+=1
                if mat[i][j]>c:print('NO');flag=1;break 
                    
        if flag:break
    if flag:continue
    print('YES')
    mat[0][0]=2;mat[0][m-1]=2;mat[n-1][0]=2;mat[n-1][m-1]=2
    mat[0][1:m-1]=[3]*(m-2)
    mat[n-1][1:m-1]=[3]*(m-2)
    for i in range(1,n-1):mat[i][0]=3;mat[i][m-1]=3
    for i in range(1,n-1):
        mat[i][1:m-1]=[4]*(m-2)
    for i in mat:
        print(*i,sep=' ')
