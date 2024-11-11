n,a,b=map(int,input().split())

A=list(map(int,input().split()))
A.sort()
print(A[b]-A[b-1])