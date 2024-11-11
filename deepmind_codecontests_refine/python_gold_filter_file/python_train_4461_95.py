A=list(map(int,input().split()))
A=sorted(A)
print(A[0] if A[1]==A[2] else A[2])