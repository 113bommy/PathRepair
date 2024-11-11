n=int(input())
A=list(map(int,input().split()))
A.sort()
print(A[n-1]-A[0])