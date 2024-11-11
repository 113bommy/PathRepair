N = int(input())
A = sorted(list(map(int,input().split())))
print(abs(sum(A[::2]) - sum(A[1::2])))