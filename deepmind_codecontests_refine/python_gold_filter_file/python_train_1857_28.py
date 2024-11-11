input()
A = sorted(list(map(int, input().split())), reverse=True)
print(sum(A[::2]) - sum(A[1::2]))