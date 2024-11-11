H,W=map(int,input().split())
C=[]
A=[]
for i in range(10):
    C.append(list(map(int,input().split())))
for i in range(H):
    A.append(list(map(int,input().split())))
# WF
for i in range(10):
    for j in range(10):
        for k in range(10):
            C[j][k]=min(C[j][k], C[j][i]+C[i][k])
print(sum(sum(C[i][1] for i in AA if i >= 0) for AA in A))