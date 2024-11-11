n = int(input())
A = list(map(int,input().split()))
A.sort()
print(A[n//2]-A[n//2-1])