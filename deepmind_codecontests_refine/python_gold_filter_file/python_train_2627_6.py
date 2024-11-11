n=int(input())
B=list(map(int,input().split()))
A=[]
maxim=B[0]
A.append(B[0])
for i in range(1,n):
    A.append(maxim+B[i])
    if A[i]>maxim:
        maxim=A[i]
A=list(map(str,A))
print(' '.join(A))