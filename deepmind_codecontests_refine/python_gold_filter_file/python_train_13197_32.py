N = int(input())
A = 2*list(map(int, input().split()))
A.sort()
print(sum(A[N:-1]))