N,M=map(int,input().split())
A=[input() for i in range(N)]
B=[input() for j in range(M)]
for i in range(N-M+1):
    for j in range(N-M+1):
        if A[i][j:j+M]==B[0]:
            if all(A[i+k][j:j+M]==B[k] for k in range(1,M)):
                print("Yes")
                exit()
print("No")