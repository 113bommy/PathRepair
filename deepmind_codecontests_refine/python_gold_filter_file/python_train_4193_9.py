for t in range(int(input())):
    r,c=map(int,input().split())
    mat=[]
    for i in range(r):
        s=input()
        mat.append(s)
    cnt=0
    if(r==1 and c==1):
        print(0)
    else:
        for i in range(c-1):
            if(mat[r-1][i]=='D'):
                cnt+=1
        for i in range(r-1):
            if(mat[i][c-1]=='R'):
                cnt+=1
        print(cnt)