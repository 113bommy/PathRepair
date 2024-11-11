A=[list(map(int,input().split())) for _ in range(3)]
b=[i for i in [int(input()) for _ in range(int(input()))] for j in A if i in j]
A=[[1 if A[i][j] in b else 0 for j in range(len(A[i]))] for i in range(len(A))]
print('NYoe s'[any([all(i) for i in A]) or any([all(i) for i in list(zip(*A))]) or all([A[0][0],A[1][1],A[2][2]]) or all([A[0][2],A[1][1],A[2][0]])::2])