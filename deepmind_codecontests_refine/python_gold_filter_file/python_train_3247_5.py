q=int(input())
for _ in range(q):
    n=int(input())
    A=[None]
    B=[None]
    for i in input():
        if i=='1' or i=='2':
            A.append(0)
        else:
            A.append(1)
    for i in input():
        if i=='1' or i=='2':
            B.append(0)
        else:
            B.append(1)
    F1=[0 for i in range(n+1)]
    F1[0]=1
    temp=1
    for i in range(1,len(A)-1):
        if temp==1:
            F1[i]=1
            if A[i]==0:
                temp=1
            elif A[i]==1 and B[i]==0:
                F1[i]=0
                break
            else:
                temp=2
        else:
            F1[i]=1
            if B[i]==0:
                temp=2
            elif B[i]==1 and A[i]==0:
                F1[i]=0
                break
            else:
                temp=1
    if F1[n-1]==1:
        if temp==1:
            if A[n]==1 and B[n]==1:
                F1[n]=1
            else:
                F1[n]=0
        else:
            if B[n]==0:
                F1[n]=1
            else:
                F1[n]=0

    flag=False
    for i in range(1,n+1):
        if F1[i]==0:
            flag=True
            break
    if flag:
        print('NO')
    else:
        print('YES')





