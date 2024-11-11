n = int(input())
A = list(map(int, input().split()))
A.sort()
print(A[n//2 - (1 if n % 2 == 0 else 0)])