import sys,math,random
input=sys.stdin.readline

T=int(input())
for _ in range(T):
    n,m=map(int,input().split())
    A=[]
    for i in range(n):
        A.append(list(map(int,input().split())))

    B=[[0 for i in range(m)] for i in range(n)]

    flag=0
    for i in range(n):
        for j in range(m):
            c=0
            if(i>0):
                c=c+1
            if(j>0):
                c=c+1
            if(i<n-1):
                c=c+1
            if(j<m-1):
                c=c+1

            B[i][j]=c
            if(A[i][j]>B[i][j]):
                flag=1
                break
        if(flag==1):
            break

    if (flag==1):
        print("NO")

    else:
        print("YES")
        for i in range(n):
            print(*B[i])
    
                
