input()
A = sorted(map(int, input().split()))[::-1]
print(sum(A[::2]) - sum(A[1::2]))
