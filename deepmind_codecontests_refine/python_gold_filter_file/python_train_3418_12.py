A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
if (sum(A)+sum(B)+sum(C))/3 == A[0]+B[1]+C[2] == A[2]+B[1]+C[0]:
    print('Yes')
else:
    print('No')