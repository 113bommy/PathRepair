N = int(input())
A = list(map(int,input().split()))*2
A.sort()
print(sum(A[N:-1]))
