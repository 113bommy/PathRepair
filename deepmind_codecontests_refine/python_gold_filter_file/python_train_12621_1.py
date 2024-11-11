import sys
input = sys.stdin.readline

def search(i,j):
    L=[]

    c=0

    while CHECK[i][j]==1<<30:
        L.append((i,j))
        
        CHECK[i][j]=c

        if MAP2[i][j]=="U":
            i-=1
        elif MAP2[i][j]=="D":
            i+=1
        elif MAP2[i][j]=="R":
            j+=1
        else:
            j-=1

        c+=1

    if (i,j) in L:
        x=CHECK[i][j]
        y=CHECK[L[-1][0]][L[-1][1]]
        loop=abs(x-y)+1

        for x,y in L:
            CHECK[x][y]%=loop
            LOOP[x][y]=loop

    else:
        loop=LOOP[i][j]
        c=CHECK[i][j]

        for x,y in L[::-1]:
            c=(c-1)%loop
            CHECK[x][y]=c
            LOOP[x][y]=loop

def search2(i,j):
    Q=[(i,j)]
    ANS=[0]*LOOP[i][j]

    while Q:
        x,y=Q.pop()

        if USE[x][y]==1:
            continue
        
        USE[x][y]=1
        if MAP[x][y]=="0":
            ANS[CHECK[x][y]]=1

        if MAP2[x][y]=="U":
            Q.append((x-1,y))
        elif MAP2[x][y]=="D":
            Q.append((x+1,y))
        elif MAP2[x][y]=="R":
            Q.append((x,y+1))
        else:
            Q.append((x,y-1))


        if 0<=x+1<n and 0<=y<m and MAP2[x+1][y]=="U":
            Q.append((x+1,y))
            
        if 0<=x-1<n and 0<=y<m and MAP2[x-1][y]=="D":
            Q.append((x-1,y))
            
        if 0<=x<n and 0<=y+1<m and MAP2[x][y+1]=="L":
            Q.append((x,y+1))
            
        if 0<=x<n and 0<=y-1<m and MAP2[x][y-1]=="R":
            Q.append((x,y-1))

    return LOOP[i][j],sum(ANS)


t=int(input())
for tests in range(t):
    n,m=map(int,input().split())
    MAP=[input().strip() for i in range(n)]
    MAP2=[input().strip() for i in range(n)]

    CHECK=[[1<<30]*m for i in range(n)]
    LOOP=[[1<<30]*m for i in range(n)]

    for i in range(n):
        for j in range(m):
            if CHECK[i][j]==1<<30:
                search(i,j)

                #print(i,j)

    #print(CHECK)
    #print(LOOP)

    USE=[[0]*m for i in range(n)]

    ANSM=0
    ANSC=0

    for i in range(n):
        for j in range(m):
            if USE[i][j]==0:
                x,y=search2(i,j)
                ANSM+=x
                ANSC+=y
    print(ANSM,ANSC)
                
            
    
    
